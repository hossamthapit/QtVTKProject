#include "ShapeOperations.h"
#include <Shape.h>

void ShapeOperations::Rotate(Shape shape,int x, int y, int z)
{
	shape.actor->RotateX(x);
	shape.actor->RotateY(y);
	shape.actor->RotateZ(z);
}

void ShapeOperations::Flip()
{
}

void ShapeOperations::Translate()
{
}

void ShapeOperations::Scale()
{
}
