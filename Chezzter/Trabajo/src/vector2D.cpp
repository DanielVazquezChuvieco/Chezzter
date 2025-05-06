#include "vector2D.h"

vector2D::vector2D()
{
	x = 0;
	y = 0;
}

vector2D::vector2D(int posx, int posy)
{
	x = posx;
	y = posy;
}

bool vector2D::operator==(const vector2D& vector)
{
	if (vector.x == x && vector.y == y)
	{
		return true;

	}
	else
		return false;
}

bool vector2D::operator!=(const vector2D& vector)
{
	if (vector.x != x || vector.y != y)
	{
		return true;

	}
	else
		return false;
}

vector2D vector2D:: operator+(vector2D vector)
{
	vector2D solucion;
	solucion.x = x + vector.x;
	solucion.y = y + vector.y;

	return solucion;
}