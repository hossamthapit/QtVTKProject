#include "Sphere.h"
#include "MainWindow.h"
#include "ui_MainWindow.h"

#include <vtkActor.h>
#include <vtkPolyDataMapper.h>
#include <Qcolordialog.h>
#include "vtkProperty.h"

#include <vtkSphereSource.h>
#include <vtkCubeSource.h>
#include <vtkCylinderSource.h>
#include <vtkConeSource.h>
#include <vtkPyramid.h>

#include <vtkActor.h>
#include <vtkCamera.h>
#include <vtkCellArray.h>
#include <vtkDataSetMapper.h>
#include <vtkNamedColors.h>
#include <vtkNew.h>
#include <vtkPoints.h>
#include <vtkProperty.h>
#include <vtkPyramid.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkRenderer.h>
#include <vtkUnstructuredGrid.h>



Sphere::Sphere() {
    source = vtkSmartPointer<vtkSphereSource>::New();

    source->SetCenter(0.0, 0.0, 0.0);
    source->SetRadius(5.0);
    source->SetPhiResolution(100);
    source->SetThetaResolution(100);

    shapeSource = source;
    setInputConnection(source->GetOutputPort());
    setMapper(mapper);

}


Cube::Cube() {
    source = vtkSmartPointer<vtkCubeSource>::New();
    source->SetXLength(8);
    source->SetYLength(8);
    source->SetZLength(8);

    shapeSource = source;
    setInputConnection(source->GetOutputPort());
    setMapper(mapper);

}

Cone::Cone()
{
    source = vtkSmartPointer<vtkConeSource>::New();
    source->SetRadius(8);
    source->SetHeight(10);

    shapeSource = source;
    setInputConnection(source->GetOutputPort());
    setMapper(mapper);
}


Cylinder::Cylinder()
{

    source = vtkSmartPointer<vtkCylinderSource>::New();
    source->SetCenter(0.0, 0.0, 0.0);
    source->SetRadius(5.0);
    source->SetHeight(7.0);
    source->SetResolution(100);

    shapeSource = source;
    setInputConnection(source->GetOutputPort());
    setMapper(mapper);
}

Pyramid::Pyramid()
{
    vtkNew<vtkPoints> points;

    float p0[3] = { 1.0, 1.0, 1.0 };
    float p1[3] = { -1.0, 1.0, 1.0 };
    float p2[3] = { -1.0, -1.0, 1.0 };
    float p3[3] = { 1.0, -1.0, 1.0 };
    float p4[3] = { 0.0, 0.0, 2 };

    points->InsertNextPoint(p0);
    points->InsertNextPoint(p1);
    points->InsertNextPoint(p2);
    points->InsertNextPoint(p3);
    points->InsertNextPoint(p4);

    vtkNew<vtkPyramid> pyramid;
    pyramid->GetPointIds()->SetId(0, 0);
    pyramid->GetPointIds()->SetId(1, 1);
    pyramid->GetPointIds()->SetId(2, 2);
    pyramid->GetPointIds()->SetId(3, 3);
    pyramid->GetPointIds()->SetId(4, 4);

    vtkNew<vtkCellArray> cells;
    cells->InsertNextCell(pyramid);

    vtkNew<vtkUnstructuredGrid> ug;
    ug->SetPoints(points);
    ug->InsertNextCell(pyramid->GetCellType(), pyramid->GetPointIds());

    vtkNew<vtkDataSetMapper> mapper;
    mapper->SetInputData(ug);

    vtkNew<vtkActor> actor;
    actor->SetMapper(mapper);

    this->actor = actor;
}
