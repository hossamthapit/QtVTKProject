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

    QObject::connect(ui->btnScale, &QPushButton::clicked, this,
        &MainWindow::onChangeScaleClick);

    QObject::connect(ui->btnDelete, &QPushButton::clicked, this,
        &MainWindow::addDeleteShapeClick);

    QObject::connect(ui->btnRedo, &QPushButton::clicked, this,
        &MainWindow::onRedoColorClick);

}

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
    if (activeShape.back().actor == NULL)return;
    QColor color = QColorDialog::getColor();
    activeShape.back().color.push(color);
    setActorColor(activeShape.back());
}


void MainWindow::onChangeScaleClick() {
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

void MainWindow::addDeleteShapeClick() {
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
    
    if (activeShape.back().color.size() > 1) {
        activeShape.back().redosColor.push(activeShape.back().color.top());
        activeShape.back().color.pop();
        setActorColor(activeShape.back());
    }
}

void MainWindow::onRedoColorClick() {

    if (activeShape.back().redosColor.size() > 0) {
        activeShape.back().color.push(activeShape.back().redosColor.top());
        activeShape.back().redosColor.pop();
        setActorColor(activeShape.back());
    }
}