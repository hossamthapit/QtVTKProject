#pragma once
#include <qcolor.h>
#include "vtkSmartPointer.h"
#include <vtkActor.h>
#include <QStack>

class Shape
{
public:
	QStack < QColor > color ;
	double scale;
	vtkSmartPointer<vtkActor> actor;

	Shape();

};

