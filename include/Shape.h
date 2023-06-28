#pragma once
#include <qcolor.h>
#include "vtkSmartPointer.h"
#include <vtkActor.h>
#include <QStack>
#include <string>
#include <vtkStdString.h>
#include <QFile>
#include <QDataStream>
#include <vtkPolyDataMapper.h>


class Shape
{
public:
	QStack < QColor > color , redosColor;
	vtkSmartPointer<vtkActor> actor;
	vtkSmartPointer<vtkPolyDataMapper> vtkShape;

	Shape();
	static Shape GetShape(QString s);
	friend QDataStream& operator<<(QDataStream& out, const Shape& obj);
	friend QDataStream& operator>>(QDataStream& out, Shape& obj);

};

