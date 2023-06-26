#include "Sphere.h"
#include "MainWindow.h"
#include "ui_MainWindow.h"

#include <vtkSphereSource.h>
#include <vtkActor.h>
#include <vtkPolyDataMapper.h>
#include <Qcolordialog.h>
#include "vtkProperty.h"


Sphere::Sphere() {
	
    scale = 1;

    setColor();

    vtkSmartPointer<vtkSphereSource> sphere = vtkSmartPointer<vtkSphereSource>::New();
    sphere->SetRadius(8);

    vtkSmartPointer<vtkPolyDataMapper> sphereMapper = vtkSmartPointer<vtkPolyDataMapper>::New();
    sphereMapper->SetInputConnection(sphere->GetOutputPort());
    
    vtkSmartPointer<vtkActor> sphereActor = vtkSmartPointer<vtkActor>::New();
    sphereActor->SetMapper(sphereMapper);
    sphereActor->GetProperty()->SetColor(color.red() / 100., color.green() / 100., color.blue() / 100);
    actor = sphereActor;
}
void Sphere::Rotate() {

}
void Sphere::Flip() {

}
void Sphere::Translate() {

}
void Sphere::Scale() {

}

void Sphere::setColor() {
    color = pickColor();
}

QColor Sphere::pickColor() {
    QColor color = QColorDialog::getColor();
    return color;
}
