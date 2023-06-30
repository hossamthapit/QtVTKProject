#include "MainWindow.h"
#include "ui_MainWindow.h"

#include <Sphere.h>
#include <Shape.h>
#include <ShapeOperations.h>
#include <vtkRenderer.h>
#include <vtkRenderWindow.h>
#include <vtkPolyDataMapper.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkInteractorStyleTrackballCamera.h>
#include <vtkCommand.h>
#include <vtkActor.h>
#include <vtkGenericOpenGLRenderWindow.h>
#include <vtkSmartPointer.h>
#include <vtkWidgetEvent.h>
#include <vtkWidgetEventTranslator.h>
#include <qcolordialog.h>
#include "vtkProperty.h"

#include <QFile>
#include <QDataStream>
#include <vtkSTLWriter.h>
#include <vtkSTLReader.h>
#include <vtkPolyDataAlgorithm.h>
#include <vtkSphereSource.h>
#include <settings.h>
#include <QMessageBox.h>



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    mRenderWindow(vtkSmartPointer<vtkGenericOpenGLRenderWindow>::New()),
    mRenderer(vtkSmartPointer<vtkRenderer>::New()),
    mInteractor(vtkSmartPointer<QVTKInteractor>::New()),
    mInteractorStyle(vtkSmartPointer<vtkInteractorStyle>::New())
{
    ui->setupUi(this);

    // set up the rendering 
    mRenderWindow->AddRenderer(mRenderer);
    mRenderWindow->SetInteractor(mInteractor);
    ui->openGLWidget->setRenderWindow(mRenderWindow);
    mInteractor->SetInteractorStyle(mInteractorStyle);
    mInteractor->Initialize();

    // set up background color
    mRenderer->SetBackground(0, 0, 0);

    setUiConnection();
    setMouseMovement();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setUiConnection() {
    QObject::connect(ui->btnDraw, &QPushButton::clicked, this,
        &MainWindow::onDrawClick);
    QObject::connect(ui->btnChooseColor, &QPushButton::clicked, this,
        &MainWindow::onChooseColorClick);
    QObject::connect(ui->btnUndo, &QPushButton::clicked, this,
        &MainWindow::onUndoColorClick);
    QObject::connect(ui->btnDelete, &QPushButton::clicked, this,
        &MainWindow::onDeleteShapeClick);
    QObject::connect(ui->btnRedo, &QPushButton::clicked, this,
        &MainWindow::onRedoColorClick);
    QObject::connect(ui->btnOpacity, &QPushButton::clicked, this,
        &MainWindow::onChangeOpacityClick);
    QObject::connect(ui->btnScale, &QPushButton::clicked, this,
        &MainWindow::onChangeScaleClick);
    QObject::connect(ui->btnFlip, &QPushButton::clicked, this,
        &MainWindow::onFlipClick);
    QObject::connect(ui->btnRotate, &QPushButton::clicked, this,
        &MainWindow::onRotateClick);
    QObject::connect(ui->btnTranslate, &QPushButton::clicked, this,
        &MainWindow::onTranslateClick);
    QObject::connect(ui->btnSave, &QPushButton::clicked, this,
        &MainWindow::onSaveFile);
    QObject::connect(ui->btnLoad, &QPushButton::clicked, this,
        &MainWindow::onLoadFile);

}    

void MainWindow::onChangeOpacityClick() {
    if (!activeShape.size())return;
    double opacity = ui->lineEdit_Opacity->text().toDouble();
    activeShape.back().actor->GetProperty()->SetOpacity(opacity);
    renderScreen();
};

void MainWindow::onTranslateClick() {
    if (!activeShape.size())return;
    double x = ui->lineEdit_Xtranslate->text().toDouble();
    double y = ui->lineEdit_Ytranslate->text().toDouble();
    double z = ui->lineEdit_Ztranslate->text().toDouble();
    activeShape.back().actor->SetPosition(x, y, z);
    renderScreen();

};
void MainWindow::onFlipClick() {
    if (!activeShape.size())return;

};

void MainWindow::onRotateClick() {
    if (!activeShape.size())return;
    double xRotation = ui->lineEdit_Xrotate->text().toDouble();
    double yRotation = ui->lineEdit_Yrotate->text().toDouble();
    double zRotation = ui->lineEdit_Zrotate->text().toDouble();
    activeShape.back().actor->RotateX(xRotation);
    activeShape.back().actor->RotateY(yRotation);
    activeShape.back().actor->RotateZ(zRotation);
    renderScreen();
};


void MainWindow::setMouseMovement() {
    vtkNew<vtkInteractorStyleTrackballCamera> style;
    mRenderWindow->GetInteractor()->SetInteractorStyle(style);

    vtkNew<vtkWidgetEventTranslator> translator;
    translator->SetTranslation(vtkCommand::LeftButtonPressEvent,
        vtkWidgetEvent::Select);

    translator->SetTranslation(vtkCommand::MouseMoveEvent,
        vtkWidgetEvent::Move);

    translator->SetTranslation(vtkCommand::LeftButtonReleaseEvent,
        vtkWidgetEvent::EndSelect);
}


void MainWindow::onChooseColorClick() {
    if (!activeShape.size())return;
    QColor color = QColorDialog::getColor();
    activeShape.back().color.push(color);
    colorShape(activeShape.back());
}

void MainWindow::colorShape(Shape shape) {
    setActorColor(shape);
}

void MainWindow::onChangeScaleClick() {
    if (!activeShape.size())return;
    double scale = ui->lineEdit_Scale->text().toDouble();
    activeShape.back().actor->SetScale(scale);
    renderScreen();
}

void MainWindow::onDrawClick() {
    Shape shape = Shape::GetShape(ui->comboBox3DObjects->currentText());
    addShapeToRenderer(shape);
    renderScreen();

}
void MainWindow::addShapeToRenderer(Shape shape) {
    mRenderer->AddViewProp(shape.actor);
    activeShape.push_back(shape);
}
void MainWindow::renderScreen() {
    mRenderer->ResetCamera();
    mRenderWindow->Render();
}

void MainWindow::onDeleteShapeClick() {
    if (!activeShape.size())return;
    removeShape(activeShape.back());
    renderScreen();
    activeShape.pop_back();
}

void MainWindow::removeShape(Shape shape) {
    mRenderer->RemoveActor(shape.actor);
}

void MainWindow::setActorColor(Shape shape) {
    QColor color = shape.color.top();
    shape.actor->GetProperty()->SetColor(color.red() / 100., color.green() / 100., color.blue() / 100);
    renderScreen();
}

void MainWindow::onUndoColorClick() {
    if (!activeShape.size())return;
    if (activeShape.back().color.size() > 1) {
        activeShape.back().redosColor.push(activeShape.back().color.top());
        activeShape.back().color.pop();
        setActorColor(activeShape.back());
    }
}

void MainWindow::onRedoColorClick() {
    if (!activeShape.size())return;
    if (activeShape.back().redosColor.size() > 0) {
        activeShape.back().color.push(activeShape.back().redosColor.top());
        activeShape.back().redosColor.pop();
        setActorColor(activeShape.back());
    }
}

void MainWindow::onSaveFile() {
    const char* mapperPath = "savedData/shapeSource.stl";
    const char* dataPath = "savedData/shapeData.bin";
    Settings::SaveShape(activeShape.back(), mapperPath, dataPath);
    ui->labelSavedLoadedMessage->setText("Saved Successfully");
}

void MainWindow::onLoadFile() {

    const char*  mapperPath = "savedData/shapeSource.stl";
    const char* dataPath = "savedData/shapeData.bin";

    Shape shape = Settings::LoadShape(mapperPath,dataPath);
    colorShape(shape);
    addShapeToRenderer(shape);
    renderScreen();
    ui->labelSavedLoadedMessage->setText("Loaded Successfully");
}
