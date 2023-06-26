#include "MainWindow.h"
#include "ui_MainWindow.h"

#include <vtkActor.h>
#include <Qcolordialog.h>
#include <Sphere.h>


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
    mRenderer->SetBackground(1, 0, 1);

    // set the ui connection
    QObject::connect(ui->pushButton, &QPushButton::clicked, this,
        &MainWindow::onDrawSphereClick);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::onDrawSphereClick() {

    Sphere s1 = Sphere();
    mRenderer->AddViewProp(s1.actor);
    mRenderer->ResetCamera();
    mRenderWindow->Render();
}