#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <Shape.h>
#include <QMainWindow>
#include <vtkGenericOpenGLRenderWindow.h>
#include <vtkRenderer.h>
#include <vtkActor.h>
#include <QVTKInteractor.h>
#include <vtkInteractorStyle.h>



namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    Ui::MainWindow* ui;

    vtkSmartPointer <vtkGenericOpenGLRenderWindow> mRenderWindow;
    vtkSmartPointer <vtkRenderer> mRenderer;
    vtkSmartPointer <QVTKInteractor> mInteractor;
    vtkSmartPointer <vtkInteractorStyle> mInteractorStyle;


public:
    Shape activeShape;

    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots :
    
    void onChooseColorClick();
    void onDrawClick();

    void onDrawSphereClick();
    void onDrawCubeClick();
    void onDrawConeClick();
    void onDrawCylinderClick();
    
    void onDrawHimisphereClick();
    void onDrawPyramidClick();
    void onDrawTubeClick();
    void onDrawDoughnutClick();
    void onDrawCurvedCylinderClick();

    void renderShape(Shape shape);
    void setMouseMovement();
    void setUiConnection();
    void setActorColor(vtkSmartPointer <vtkActor> actor, QColor color);
    void onUndoColorClick();
    // void changeOpacity();
};

#endif // MAINWINDOW_H
