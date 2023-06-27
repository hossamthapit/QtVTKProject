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
    QColor color = QColorDialog::getColor();
    activeActor->GetProperty()->SetColor(color.red() / 100., color.green() / 100., color.blue() / 100);
    mRenderer->ResetCamera();
    mRenderWindow->Render();
}

void MainWindow::onDrawClick() {


    if (ui->comboBox3DObjects->currentText() == "Sphere") {
        onDrawSphereClick();
    }
    else if (ui->comboBox3DObjects->currentText() == "Cube") {
        onDrawCubeClick();
    }
    else if (ui->comboBox3DObjects->currentText() == "Cone") {
        onDrawConeClick();
    }
    else if (ui->comboBox3DObjects->currentText() == "Cylinder") {
        onDrawCylinderClick();
    }
    else if (ui->comboBox3DObjects->currentText() == "Pyramid") {
        onDrawPyramidClick();
    }
    else if (ui->comboBox3DObjects->currentText() == "Tube") {
        onDrawTubeClick();
    }
    else if (ui->comboBox3DObjects->currentText() == "Doughnut") {
        onDrawDoughnutClick();
    }
    else if (ui->comboBox3DObjects->currentText() == "CurvedCylinder") {
        onDrawCurvedCylinderClick();
    }
    else if (ui->comboBox3DObjects->currentText() == "Himisphere") {
        onDrawHimisphereClick();
    }
}


void MainWindow::onDrawSphereClick() {
    Shape shape = Sphere();
    renderShape(shape);
}
void MainWindow::onDrawCubeClick() {
    Shape shape = Cube();
    renderShape(shape);
}
void MainWindow::onDrawConeClick() {
    Shape shape = Cone();
    renderShape(shape);
}
void MainWindow::onDrawCylinderClick() {
    Shape shape = Cylinder();
    renderShape(shape);
}
void MainWindow::onDrawPyramidClick() {
    Shape shape = Pyramid();
    renderShape(shape);
}

void MainWindow::renderShape(Shape shape) {
    mRenderer->RemoveActor(activeActor);
    mRenderer->AddViewProp(shape.actor);
    mRenderer->ResetCamera();
    mRenderWindow->Render();
    activeActor = shape.actor;
}

void MainWindow::onDrawTubeClick() {

}
void MainWindow::onDrawHimisphereClick() {}
void MainWindow::onDrawDoughnutClick() {}
void MainWindow::onDrawCurvedCylinderClick() {}
