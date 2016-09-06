#include "gfw.hpp"
#include <iostream>
#include <chrono>

#include "MyScreen.hpp"
#include "timer.hpp"
#include "create_window.hpp"

int main ()
{
	/*----------------------- SDL INIT and OpenGL set versions ----------------------*/
	SDL_Init(SDL_INIT_VIDEO|SDL_INIT_TIMER);

	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
	/*----------------------------------------------------------------------------*/
	MyScreen s;

	gfw::Window* first_window = create_window ("Test");
	first_window->attach (&s);

	bool exit = false;

	while (!exit)
	{
		while (true)
		{
			SDL_Event ev;
			int r = SDL_WaitEventTimeout (&ev, timer.timeout);
			timer.timeout = 0;
			if (r < 0)
				throw std::runtime_error ("event");
			if (!r)
				break;
			if (ev.type == SDL_WINDOWEVENT)
				gfw::Window::_dispatch_window (ev);
			else if (ev.type == SDL_QUIT)
			{
				exit = true;
				break;
			}
		}
		timer.next_timeout (first_window);
	}
	s.gl_detach ();
	return 0;
}
