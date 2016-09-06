#include "gfw.hpp"
#include <iostream>
#include <chrono>

struct MyScreen: gfw::Screen{
	GLuint program;
	
	GLuint buf1;

	GLuint verts;

	void render(uint width, uint height) override{
		(void)width;
		(void)height;
		gl->UseProgram(program);

		GLuint draw_ind[][3]={
			{0,1,2}
		};
		gl->BindVertexArray(verts);
		glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, draw_ind);
	}

	void gl_init() override{
		program=gfw::make_program(gl, {
			gfw::make_shader(gl, GL_VERTEX_SHADER, "vertex.glsl"),
			gfw::make_shader(gl, GL_FRAGMENT_SHADER, "fragment.glsl"),
		});

		gl->GenBuffers(1, &buf1);
		gl->GenVertexArrays(1, &verts);

		size_t n=3;
		gfw::Vec<GLfloat,3> buf1_data[n]={
			{0,0,0},
			{1,0,0},
			{0,1,0},
		};

		gl->BindVertexArray(verts);
		gl->EnableVertexAttribArray(0);
		gl->BindBuffer(GL_ARRAY_BUFFER, buf1);
		gl->BufferData(GL_ARRAY_BUFFER, n*sizeof(GLfloat)*3, buf1_data, GL_STATIC_READ);
		gl->VertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, nullptr);
		gl->BindBuffer(GL_ARRAY_BUFFER, 0);
		gl->BindVertexArray(0);
		if(glGetError()){
			std::cerr<<"bind: GL error\n";
		}
	}

	void gl_deinit() override{
		gl->DeleteBuffers(1, &buf1);
		gl->DeleteVertexArrays(1, &verts);
		gl->DeleteProgram(program);
	}
};

int main(){
	SDL_Init(SDL_INIT_VIDEO|SDL_INIT_TIMER);

	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);

	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_Window *win=SDL_CreateWindow("Test", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_RESIZABLE|SDL_WINDOW_OPENGL);
	if(!win) throw std::runtime_error(SDL_GetError());
	auto w=gfw::Window(win);

	MyScreen s;

	w.attach(&s);

	std::chrono::steady_clock::time_point next_frame=std::chrono::steady_clock::now();
	auto frame_time=std::chrono::milliseconds(17);

	int timeout=0;

	bool exit=false;

	while(!exit){
		while(true){
			SDL_Event ev;
			int r=SDL_WaitEventTimeout(&ev, timeout);
			timeout=0;
			if(r<0) throw std::runtime_error("event");
			if(!r) break;
			if(ev.type==SDL_WINDOWEVENT){
				gfw::Window::_dispatch_window(ev);
			}else if(ev.type==SDL_QUIT){
				exit=true;
				break;
			}
		}

		std::chrono::steady_clock::time_point now=std::chrono::steady_clock::now();
		if(now>=next_frame){
			w._render();
			next_frame+=frame_time;
			now=std::chrono::steady_clock::now();
			if(next_frame<now){
				next_frame=now;
			}
		}else{
			timeout=std::chrono::duration_cast<std::chrono::milliseconds>(next_frame-now).count();
		}
	}
	s.gl_detach();

	return 0;
}
