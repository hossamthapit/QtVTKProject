#pragma once
#include <qcolor.h>
#include "vtkSmartPointer.h"
#include <vtkActor.h>
#include <Shape.h>
#include <ShapeOperations.h>


class Sphere :public Shape
{
private:
	double radius;

public:
	Sphere();

};

class Cube : public Shape
{
private:
	double length;

public:
	Cube();
};

class Himisphere : public Shape
{
private:
	double length;

public:
	Himisphere();
};

class Cone : public Shape
{
private:
	double radius;
	double height;
public:
	Cone();
};
class Pyramid : public Shape
{
private:
	double length;

public:
	Pyramid();
};
class Cylinder : public Shape
{
private:
	double radius;
	double height;

public:
	Cylinder();
};
class Tube : public Shape
{
private:
	double length;

public:
	Tube();
};
class Doughnut : public Shape
{
private:
	double length;

public:
	Doughnut();
};
class CurvedCylinder : public Shape
{
private:
	double length;

public:
	CurvedCylinder();
};
