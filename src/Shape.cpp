#include "Shape.h"
#include "Sphere.h"
#include "MainWindow.h"
#include "ui_MainWindow.h"

#include <vtkSphereSource.h>
#include <vtkActor.h>
#include <vtkPolyDataMapper.h>
#include <Qcolordialog.h>
#include "vtkProperty.h"
#include <vtkPolyDataAlgorithm.h>
#include <vtkAlgorithmOutput.h>

Shape::Shape() {
    actor = vtkSmartPointer<vtkActor>::New();
    mapper = vtkSmartPointer<vtkPolyDataMapper>::New();
    shapeSource = vtkSmartPointer<vtkPolyDataAlgorithm>::New();
}

void Shape::setInputConnection(vtkSmartPointer<vtkAlgorithmOutput> algorithmOutput) {
    mapper->SetInputConnection(algorithmOutput);
}
void Shape::setMapper(vtkSmartPointer<vtkPolyDataMapper> tempMapper) {
    actor->SetMapper(tempMapper);
}


Shape Shape::GetShape(QString shape) {
    Shape obj;

    if (shape == "Sphere") {
        obj = Sphere();
    }
    else if (shape == "Cube") {
        obj = Cube();
    }
    else if (shape == "Cone") {
        obj = Cone();
    }
    else if (shape == "Cylinder") {
        obj = Cylinder();
    }
    else if (shape == "Pyramid") {
        obj = Pyramid();
    }
    return obj;
}

QDataStream& operator<<(QDataStream& out, const Shape& obj) {
    out <<  obj.color << obj.redosColor;
    return out;
}

QDataStream& operator>>(QDataStream& in, Shape& obj) {
    in >> obj.color >> obj.redosColor;
    return in;
}