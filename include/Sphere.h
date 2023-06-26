#pragma once
#include <qcolor.h>
#include "vtkSmartPointer.h"
#include <vtkActor.h>
#include <Shape.h>


class Sphere : Shape
{
private:
	double radius;

public:
	vtkSmartPointer<vtkActor> actor;
	Sphere();

};

class Cube : Shape
{
private:
	double length;

public:
	vtkSmartPointer<vtkActor> actor;
	Cube();
};

class Himisphere : Shape
{
private:
	double length;

public:
	vtkSmartPointer<vtkActor> actor;
	Himisphere();
};

class Cone : Shape
{
private:
	double radius;
	double height;
public:
	vtkSmartPointer<vtkActor> actor;
	Cone();
};
class Pyramid : Shape
{
private:
	double length;

public:
	vtkSmartPointer<vtkActor> actor;
	Pyramid();
};
class Cylinder : Shape
{
private:
	double radius;
	double height;

public:
	vtkSmartPointer<vtkActor> actor;
	Cylinder();
};
class Tube : Shape
{
private:
	double length;

public:
	vtkSmartPointer<vtkActor> actor;
	Tube();
};
class Doughnut : Shape
{
private:
	double length;

public:
	vtkSmartPointer<vtkActor> actor;
	Doughnut();
};
class CurvedCylinder : Shape
{
private:
	double length;

public:
	vtkSmartPointer<vtkActor> actor;
	CurvedCylinder();
};
