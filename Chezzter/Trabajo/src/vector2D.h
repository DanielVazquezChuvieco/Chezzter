#pragma once
class vector2D
{
public:
	int x;
	int y;

	vector2D();
	vector2D(int posx, int posy);

	bool operator == (const vector2D& vector);
	vector2D operator+(vector2D vector);
	bool operator!=(const vector2D& vector);
};

