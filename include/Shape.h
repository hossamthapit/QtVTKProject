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
#include <vtkPolyDataAlgorithm.h>
#include <vtkAlgorithmOutput.h>



class Shape
{

protected:
	void setMapper(vtkSmartPointer<vtkPolyDataMapper> mapper);
	void setInputConnection(vtkSmartPointer<vtkAlgorithmOutput> mapper);

public:
	QStack < QColor > color , redosColor;
	vtkSmartPointer<vtkActor> actor;
	vtkSmartPointer<vtkPolyDataMapper> mapper;
	vtkSmartPointer<vtkPolyDataAlgorithm> shapeSource;


	Shape();
	static Shape GetShape(QString s);
	friend QDataStream& operator<<(QDataStream& out, const Shape& obj);
	friend QDataStream& operator>>(QDataStream& out, Shape& obj);

};

