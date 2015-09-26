	void print_segment (point a, point b, float red = 1.0f, float green = 1.0f, float blue = 0.0f)
	{
			glColor3f(red,green,blue);
			glVertex2f(a.x,a.y);
			glVertex2f(b.x,b.y);
	}

	#include "base_print.hpp"
	
	#include "make_triangulations.hpp"
