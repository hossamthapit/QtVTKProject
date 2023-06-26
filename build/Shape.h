#pragma once
#include <qcolor.h>
#include "vtkSmartPointer.h"
#include <vtkActor.h>

class Shape
{
public:
	QColor color;
	double scale;

public:
	vtkSmartPointer<vtkActor> actor;
	Shape();
	void Rotate();
	void Flip();
	void Translate();
	void Scale();
	void setColor();
	QColor pickColor();

};

