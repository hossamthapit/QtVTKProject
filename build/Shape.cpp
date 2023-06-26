#include "Shape.h"
#include "MainWindow.h"
#include "ui_MainWindow.h"

#include <vtkSphereSource.h>
#include <vtkActor.h>
#include <vtkPolyDataMapper.h>
#include <Qcolordialog.h>
#include "vtkProperty.h"

Shape::Shape() {
    setColor();
}
void Shape::Rotate() {

}
void Shape::Flip() {

}
void Shape::Translate() {

}
void Shape::Scale() {

}

void Shape::setColor() {
    color = pickColor();
}

QColor Shape::pickColor() {
    QColor color = QColorDialog::getColor();
    return color;
}
