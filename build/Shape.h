#pragma once
#include <qcolor.h>
#include "vtkSmartPointer.h"
#include <vtkActor.h>

class Shape
{
public:
	QColor color;
	double scale;
	vtkSmartPointer<vtkActor> actor;

	Shape();
	void setColor();
	QColor pickColor();

};

