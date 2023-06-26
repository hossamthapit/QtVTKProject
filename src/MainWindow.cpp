#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <consoleapi.h>
#include <vtkActor.h>
#include <Qcolordialog.h>
#include <Sphere.h>
#include <Shape.h>
#include <ShapeOperations.h>


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
    mRenderer->SetBackground(0, 0, 1);

    // set the ui connection
    QObject::connect(ui->btnDraw, &QPushButton::clicked, this,
        &MainWindow::onDrawClick);

    QObject::connect(ui->btnChooseColor, &QPushButton::clicked, this,
        &MainWindow::onChooseColorClick);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onChooseColorClick() {
    QColor color = QColorDialog::getColor();
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

}


void MainWindow::onDrawSphereClick() {

    Shape shape = Sphere();
    ShapeOperations::Rotate(shape, 22, 22, 0);
    renderShape(shape);
}

void MainWindow::onDrawCubeClick() {

    Shape shape = Cube();
    ShapeOperations::Rotate(shape, 22, 22, 0);
    mRenderer->AddViewProp(shape.actor);
    renderShape(shape);
}
void MainWindow::onDrawConeClick() {

    Shape shape = Cone();
    ShapeOperations::Rotate(shape, 22, 22, 0);
    renderShape(shape);
}
void MainWindow::onDrawCylinderClick() {

    Shape shape = Cylinder();
    ShapeOperations::Rotate(shape, 22, 0, 0);
    renderShape(shape);
}

void MainWindow::renderShape(Shape shape) {
    mRenderer->AddViewProp(shape.actor);
    mRenderer->ResetCamera();
    mRenderWindow->Render();
}

void MainWindow::onDrawHimisphereClick() {}
void MainWindow::onDrawPyramidClick() {}
void MainWindow::onDrawTubeClick() {}
void MainWindow::onDrawDoughnutClick() {}
void MainWindow::onDrawCurvedCylinderClick() {}
