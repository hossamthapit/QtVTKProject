#include "Shape.h"
#include "Sphere.h"
#include "MainWindow.h"
#include "ui_MainWindow.h"

#include <vtkSphereSource.h>
#include <vtkActor.h>
#include <vtkPolyDataMapper.h>
#include <Qcolordialog.h>
#include "vtkProperty.h"

Shape::Shape() {
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
    else if (shape == "Tube") {
        obj = Tube();
    }

    return obj;
}

