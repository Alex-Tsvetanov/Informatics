#include <stdio.h>
#include <iostream>
#include <math.h>

#include <unistd.h>

#include <vector>
#include <utility>
#include <set>

#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#define ESCAPE 27

using namespace std;

#include "openGL.base.hpp"
#include "point.hpp"
int sleep_sec;
#include "print.hpp"

int main (int argc, char** args)
{
	cin >> sleep_sec;
	int n;
	cin >> n;
	for (int i = 0 ; i < n ; i ++)
	{
		float x, y;
		cin >> x >> y;
		polygon.push_back (point (x * 4, y * 4));
	}

	gen_LN ();
	gen_hard ();

	//cout << edges.size () << endl;
	//cout << allHard.size () << endl;

	glutInit(&argc, args);  

	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_ALPHA | GLUT_DEPTH);  

	glutInitWindowSize(640, 600);  

	glutInitWindowPosition(0, 0);  

	window = glutCreateWindow("Triangulation of Polygon");  

	glutDisplayFunc(gen_hard_printer);  

	glutFullScreen();

	glutIdleFunc(gen_hard_printer);

	glutReshapeFunc(&ReSizeGLScene);

	glutKeyboardFunc(&keyPressed);

	InitGL(640, 480);

	glutMainLoop();  
}
