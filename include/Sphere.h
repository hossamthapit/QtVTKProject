#pragma once
#include <qcolor.h>
#include "vtkSmartPointer.h"
#include <vtkActor.h>
#include <Shape.h>
#include <ShapeOperations.h>
#include <vtkPolyDataMapper.h>
#include <QFile>
#include <QDataStream>


class Sphere :public Shape
{
private:

public:
	Sphere();
};

class Cube : public Shape
{
private:

public:
	Cube();
};

class Cone : public Shape
{
private:

public:
	Cone();
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
};