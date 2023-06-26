#pragma once
#include <qcolor.h>
#include "vtkSmartPointer.h"
#include <vtkActor.h>


class Sphere
{
private:
	QColor color;
	double scale;

public:
	vtkSmartPointer<vtkActor> actor;
	Sphere();
	void Rotate();
	void Flip();
	void Translate();
	void Scale();
	void setColor();
	QColor pickColor();
};

