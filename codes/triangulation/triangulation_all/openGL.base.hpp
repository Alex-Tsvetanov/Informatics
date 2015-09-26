	int sv;
	int window;
	void InitGL(int Width, int Height)
	{

	   GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	   GLfloat mat_shininess[] = { 50.0 };
	   GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };
	   glClearColor (0.0, 0.0, 0.0, 0.0);
	   glShadeModel (GL_SMOOTH);

	   glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	   glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
	   glLightfv(GL_LIGHT0, GL_POSITION, light_position);

	   glEnable(GL_LIGHTING);
	   glEnable(GL_LIGHT0);

	  glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	  glClearDepth(1.0);				
	  glDepthFunc(GL_LESS);			
	  glEnable(GL_DEPTH_TEST);			
	  glShadeModel(GL_SMOOTH);			

	  glMatrixMode(GL_PROJECTION);
	  glLoadIdentity();

	  gluPerspective(45.0f,(GLfloat)Width/(GLfloat)Height,0.1f,100.0f);

	  glMatrixMode(GL_MODELVIEW);
	}

	void ReSizeGLScene(int Width, int Height)
	{
	  if (Height==0)
		Height=1;

	  glViewport(0, 0, Width, Height);

	  glMatrixMode(GL_PROJECTION);
	  glLoadIdentity();

	  gluPerspective(45.0f,(GLfloat)Width/(GLfloat)Height,0.1f,100.0f);
	  glMatrixMode(GL_MODELVIEW);
	}

	void keyPressed(unsigned char key, int x, int y) 
	{
		if (key == ESCAPE or key == 'q') 
		{ 
			glutDestroyWindow(window); 
			
			exit(0);                   
		}
	}
