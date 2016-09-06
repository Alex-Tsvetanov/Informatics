#pragma once
#include "gfw.hpp"

struct MyScreen : gfw::Screen
{
	GLuint program;
	
	GLuint buf1;
	GLuint buf2;

	GLuint verts;

	void render (uint width, uint height) override
	{
		(void) width;
		(void) height;
		gl->UseProgram (program);

		GLuint draw_ind [][3]=
		{
			{0,1,2},
			{3,1,2}
		};
		gl->BindVertexArray (verts);
		glDrawElements (GL_TRIANGLES, 3 * 2, GL_UNSIGNED_INT, draw_ind);
	}

	void gl_init() override
	{
		program=gfw::make_program(gl, {
			gfw::make_shader(gl, GL_VERTEX_SHADER, "./OpenGL/vertex.glsl"),
			gfw::make_shader(gl, GL_FRAGMENT_SHADER, "./OpenGL/fragment.glsl"),
		});

		gl->GenBuffers(1, &buf1);
		gl->GenBuffers(1, &buf2);
		gl->GenVertexArrays(1, &verts);

		size_t n=4;
		gfw::Vec<GLfloat,3> buf1_data[n]={
			{0,0,0},
			{1,0,0},
			{0,1,0},
			{1,1,0}
		};
		gfw::Vec<GLfloat,3> buf2_data[n]={
			{0,0,0},
			{1,0,0},
			{0,1,0},
			{1,1,0}
		};

		gl->BindVertexArray(verts);
		gl->EnableVertexAttribArray(0);
		{
			gl->BindBuffer(GL_ARRAY_BUFFER, buf1);
			gl->BufferData(GL_ARRAY_BUFFER, n*sizeof(GLfloat)*3, buf1_data, GL_STATIC_READ);
			gl->VertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, nullptr);
			gl->BindBuffer(GL_ARRAY_BUFFER, 0);
		}
		{
			gl->BindBuffer(GL_ARRAY_BUFFER, buf2);
			gl->BufferData(GL_ARRAY_BUFFER, n*sizeof(GLfloat)*3, buf2_data, GL_STATIC_READ);
			gl->VertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, nullptr);
			gl->BindBuffer(GL_ARRAY_BUFFER, 0);
		}
		gl->BindVertexArray(0);
		if(glGetError())
		{
			std::cerr<<"bind: GL error\n";
		}
	}

	void gl_deinit() override
	{
		gl->DeleteBuffers(1, &buf1);
		gl->DeleteBuffers(1, &buf2);
		gl->DeleteVertexArrays(1, &verts);
		gl->DeleteProgram(program);
	}
};
