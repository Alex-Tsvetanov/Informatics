#pragma once

struct
{
	int timeout = 0;

	std::chrono::steady_clock::time_point next_frame = std::chrono::steady_clock::now ();
	std::chrono::milliseconds frame_time = std::chrono::milliseconds (17);

	void next_timeout (gfw::Window* win)
	{
		std::chrono::steady_clock::time_point now = std::chrono::steady_clock::now ();
		if (now >= next_frame)
		{
			win->_render ();
			next_frame += frame_time;
			now = std::chrono::steady_clock::now ();
			if (next_frame < now)
				next_frame = now;
		}
		else
			timeout = std::chrono::duration_cast <std::chrono::milliseconds> (next_frame - now).count ();
	}
} timer;
