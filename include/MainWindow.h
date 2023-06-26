#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vtkGenericOpenGLRenderWindow.h>
#include <vtkRenderer.h>
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
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots :
    
    void onDrawSphereClick();
    //void onDrawCubeClick();
    //void onDrawHimisphereClick();
    //void onDrawConeClick();
    //void onDrawPyramidClick();
    //void onDrawCylinderClick();
    //void onDrawTubeClick();
    //void onDrawDoughnutClick();
    //void onDrawCurvedCylinderClick();

   // void changeColor();
   // void changeOpacity();

};

#endif // MAINWINDOW_H
