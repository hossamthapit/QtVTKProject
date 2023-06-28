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
    
    void setUiConnection();
    void setMouseMovement();
    
    void onDrawClick();
    void removeShape(Shape shape);

    void onChooseColorClick();
    void onUndoColorClick();
    void onRedoColorClick();

    void addShapeToRenderer(Shape shape);
    void setActorColor(Shape shape);
    void renderScreen();

    void onDeleteShapeClick();

    void onChangeOpacityClick();
    void onChangeScaleClick();
    void onFlipClick();
    void onRotateClick();
    void onTranslateClick();

    void onSaveFile();
    void onLoadFile();
};

#endif // MAINWINDOW_H
