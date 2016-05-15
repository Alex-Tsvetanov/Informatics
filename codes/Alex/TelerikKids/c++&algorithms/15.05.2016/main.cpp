#include <iostream>

using std::cin;
using std::cout;

#ifdef _WIN32
    #include <windows.h>

    void sleep(unsigned milliseconds)
    {
        Sleep(milliseconds);
    }
#else
    #include <unistd.h>

    void sleep(unsigned milliseconds)
    {
        usleep(milliseconds * 1000); // takes microseconds
    }
#endif

void draw (const char** map, const int gridX, const int gridY, const int _1_x, const int _1_y, const int _2_x, const int _2_y)
{
	for (int i  = 0 ; i < gridY ; i ++, cout << '\n') 
		for (int j  = 0 ; j < gridX ; j ++) 
			cout << map [i][j];
}

int main ()
{
	int gridX, gridY;
	cin >> gridX >> gridY;
	char** map = new char* [gridY];
	for (int i = 0 ; i < gridY ; i ++)
	{
		map [i] = new char [gridX];
		for (int j = 0 ; j < gridY ; j ++)
			map [i][j] = ' ';
	}

	int _1_x, _1_y;
	int _2_x, _2_y;
	cin >> _1_x >> _1_y >> _2_x >> _2_y;

	player player1 = AlexRo6afF (1);		
	return 0;
}
