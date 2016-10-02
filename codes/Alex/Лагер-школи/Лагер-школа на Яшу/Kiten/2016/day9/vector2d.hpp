#pragma once

struct vector2d
{
private:
	double x, y;
public:
	vector2d (double x = 0, double y = 0)
	{
		this->x = x;
		this->y = y;
	}

	vector2d (double x1, double y1, double x2, double y2)
	{
		x = x1 - x2;
		y = y1 - y2;
	}

	friend vector2d operator + (const vector2d &, const vector2d &);
	friend vector2d operator - (const vector2d &, const vector2d &);
	friend double cross_product (const vector2d &, const vector2d &);
	friend double dot_product (const vector2d &, const vector2d &);

	double X () const
	{
		return x;
	}

	double Y () const
	{
		return y;
	}
};

vector2d operator + (const vector2d& a, const vector2d& b)
{
	return vector2d ({a.x + b.x, a.y + b.y});
}

vector2d operator - (const vector2d& a, const vector2d& b)
{
	return vector2d ({a.x - b.x, a.y - b.y});
}

double cross_product (const vector2d& a, const vector2d& b)
{
	return a.x * b.y - a.y * b.x;
}

double dot_product (const vector2d& a, const vector2d& b)
{
	return a.x * b.x + a.y * b.y;
}
