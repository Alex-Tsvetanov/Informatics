#include <iostream>
#define max(X,Y) (((X) < (Y))?(Y):(X))
#define min(X,Y) (((X) > (Y))?(Y):(X))

using namespace std;

int maxX = -1e9, minX = 1e9, maxY = -1e9, minY = 1e9;

int main ()
{
	int greenX, greenY, greenW, greenH;
	cin >> greenX >> greenY >> greenW >> greenH;
	int n;
	cin >> n;
	for (int i = 0 ; i < n ; i ++)
	{
		int x, y, w, h;
		cin >> x >> y >> w >> h;
		maxX = max (maxX, x);
		minX = min (minX, x - w);
		maxY = max (maxY, y);
		minY = min (minY, y - h);
	}
	if ((maxX > greenX) or (maxX == greenX and maxY > greenY))
		maxX = greenX, maxY = greenY;
	cout << maxX << " " << maxY << " " << maxX - minX << " " << maxY - minY << endl;
}
