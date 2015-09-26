	#define make_func_print_triangulation(name,arr,counter) \
	int counter; \
	void name () \
	{ \
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); \
		glLoadIdentity(); \
		    glDisable(GL_LIGHTING); \
		    glDisable(GL_LIGHT0); \
			glTranslatef(-5.5f,0.0f,-30.0f);\
			glLineWidth(2);\
			glBegin(GL_LINES);\
				for (auto& x : arr [counter])\
					print_segment (polygon [edges [x].first], polygon [edges [x].second]);\
			glEnd();\
			counter ++;\
			counter %= arr.size ();\
			glLineWidth(2);\
			glBegin(GL_LINES);\
				for (int i = 0 ; i < (int)polygon.size () ; i ++)\
				{\
					glColor3f(1.0f,0.0f,0.0f);\
					glVertex2f(polygon [i].x,polygon [i].y);\
					glVertex2f(polygon [(i + 1) % polygon.size ()].x,polygon [(i + 1) % polygon.size ()].y);\
				}\
			glEnd();\
			/*glColor3f(1.0f,0.0f,0.0f);\
			glBegin(GL_POLYGON);\
				for (auto& x : polygon)\
					glVertex3f(x.x, x.y, 0.0f);\
			glEnd();\*/ \
		glutSwapBuffers();\
		sleep (sleep_sec);\
	}

	#define make_simply_func_print_triangulation(name,arr,counter) \
	int counter; \
	void name () \
	{ \
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); \
		glLoadIdentity(); \
		    glDisable(GL_LIGHTING); \
		    glDisable(GL_LIGHT0); \
			glTranslatef(-5.5f,0.0f,-30.0f);\
			glLineWidth(2);\
			glBegin(GL_LINES);\
				for (auto& x : arr [counter])\
					print_segment (polygon [x.first], polygon [x.second]);\
			glEnd();\
			counter ++;\
			counter %= arr.size ();\
			glLineWidth(2);\
			glBegin(GL_LINES);\
				for (int i = 0 ; i < (int)polygon.size () ; i ++)\
				{\
					glColor3f(1.0f,0.0f,0.0f);\
					glVertex2f(polygon [i].x,polygon [i].y);\
					glVertex2f(polygon [(i + 1) % polygon.size ()].x,polygon [(i + 1) % polygon.size ()].y);\
				}\
			glEnd();\
			glColor3f(1.0f,0.0f,0.0f);\
			glBegin(GL_POLYGON);\
				for (auto& x : polygon)\
					glVertex3f(x.x, x.y, 0.0f);\
			glEnd();\
		glutSwapBuffers();\
		sleep (sleep_sec);\
	}
