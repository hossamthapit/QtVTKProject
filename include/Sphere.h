#pragma once
#include <qcolor.h>
#include "vtkSmartPointer.h"
#include <vtkActor.h>
#include <Shape.h>
#include <ShapeOperations.h>
#include <vtkPolyDataMapper.h>
#include <QFile>
#include <QDataStream>
#include <vtkSphereSource.h>
#include <vtkCylinderSource.h>
#include <vtkCubeSource.h>
#include <vtkConeSource.h>
#include <vtkPyramid.h>


class Sphere :public Shape
{
private:

public:
	Sphere();
	vtkSmartPointer<vtkSphereSource> source;
};

class Cube : public Shape
{
private:

public:
	Cube();
	vtkSmartPointer<vtkCubeSource> source;
};

class Cone : public Shape
{
private:

public:
	Cone();
	vtkSmartPointer<vtkConeSource> source;
};
class Pyramid : public Shape
{
private:

public:
	Pyramid();
};
class Cylinder : public Shape
{
private:

public:
	Cylinder();
	vtkSmartPointer<vtkCylinderSource> source;
};