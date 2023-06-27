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

vtkSmartPointer<vtkActor> setShapeActor(QColor color, vtkSmartPointer<vtkPolyDataMapper> shapeMapper);

Sphere::Sphere() {
	
    vtkSmartPointer<vtkSphereSource> sphere = vtkSmartPointer<vtkSphereSource>::New();
    
    sphere->SetCenter(0.0, 0.0, 0.0);
    sphere->SetRadius(5.0);
    // Make the surface smooth.
    sphere->SetPhiResolution(100);
    sphere->SetThetaResolution(100);

    vtkSmartPointer<vtkPolyDataMapper> sphereMapper = vtkSmartPointer<vtkPolyDataMapper>::New();
    sphereMapper->SetInputConnection(sphere->GetOutputPort());
    
    actor = setShapeActor(color.top(), sphereMapper);

}

Cube::Cube() {
    vtkSmartPointer<vtkCubeSource> cube = vtkSmartPointer<vtkCubeSource>::New();
    cube->SetXLength(8);
    cube->SetYLength(8);
    cube->SetZLength(8);

    vtkSmartPointer<vtkPolyDataMapper> cubeMapper = vtkSmartPointer<vtkPolyDataMapper>::New();
    cubeMapper->SetInputConnection(cube->GetOutputPort());

    actor = setShapeActor(color.top(), cubeMapper);

}

Cone::Cone()
{
    vtkSmartPointer<vtkConeSource> cone = vtkSmartPointer<vtkConeSource>::New();
    cone->SetRadius(8);
    cone->SetHeight(10);

    vtkSmartPointer<vtkPolyDataMapper> coneMapper = vtkSmartPointer<vtkPolyDataMapper>::New();
    coneMapper->SetInputConnection(cone->GetOutputPort());

    actor = setShapeActor(color.top(), coneMapper);
}


Cylinder::Cylinder()
{

    vtkSmartPointer<vtkCylinderSource> cylinder = vtkSmartPointer<vtkCylinderSource>::New();
    cylinder->SetCenter(0.0, 0.0, 0.0);
    cylinder->SetRadius(5.0);
    cylinder->SetHeight(7.0);
    cylinder->SetResolution(100);


    vtkSmartPointer<vtkPolyDataMapper> cylinderMapper = vtkSmartPointer<vtkPolyDataMapper>::New();
    cylinderMapper->SetInputConnection(cylinder->GetOutputPort());

    actor = setShapeActor(color.top(), cylinderMapper);
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
Tube::Tube()
{

}

vtkSmartPointer<vtkActor> setShapeActor(QColor color, vtkSmartPointer<vtkPolyDataMapper> shapeMapper) {
    vtkSmartPointer<vtkActor> shapeActor = vtkSmartPointer<vtkActor>::New();
    shapeActor->SetMapper(shapeMapper);
    return shapeActor;
}
