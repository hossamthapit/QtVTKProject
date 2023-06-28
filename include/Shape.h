#pragma once
#include <qcolor.h>
#include "vtkSmartPointer.h"
#include <vtkActor.h>
#include <QStack>
#include <string>
#include <vtkStdString.h>

class Shape
{
public:
	QStack < QColor > color , redosColor;
	double scale;
	vtkSmartPointer<vtkActor> actor;

	Shape();
	static Shape GetShape(QString s);

};

