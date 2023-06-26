#pragma once
#include <Shape.h>

class ShapeOperations
{
public :
	static void Rotate(Shape shape, int x, int y, int z);
	static void Flip();
	static void Translate();
	static void Scale();

};

