#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <Shape.h>
#include <QMainWindow>
#include <vtkGenericOpenGLRenderWindow.h>
#include <vtkRenderer.h>
#include <vtkActor.h>
#include <QVTKInteractor.h>
#include <vtkInteractorStyle.h>
#include <qvector.h>


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
    QVector < Shape > activeShape;
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots :
    
    void onChooseColorClick();
    void onDrawClick();
    void onChangeScaleClick();
    void removeShape(Shape shape);

    void renderScreen();
    void addShapeToRenderer(Shape shape);
    void addDeleteShapeClick();
    void setMouseMovement();
    void setUiConnection();
    void setActorColor(Shape shape);
    void onUndoColorClick();
    void onRedoColorClick();
    // void changeOpacity();
};

#endif // MAINWINDOW_H
