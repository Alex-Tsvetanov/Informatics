#include <cstdio>
#include <stack>
#include <utility>
using namespace std;
#include "bitmap_image.hpp"

bitmap_image  input = bitmap_image ("./input.bmp");
const unsigned int height = input.height();
const unsigned int width  = input.width();

bool** visited;

const int X [4] = {0, 0, -1, 1};
const int Y [4] = {1, -1, 0, 0};
unsigned int circles;

void dfs (int y, int x)
{
   stack <pair < int, int > > s;
   s.push ({y, x});
   while (!s.empty ())
   {
      y = s.top ().first;
      x = s.top ().second;
      s.pop ();
      visited [y][x] = 1;
      for (int i = 0 ; i < ((int)((sizeof (X)/ sizeof (X [0])))) ; i ++)
      {
         int newX = x + X [i];
         int newY = y + Y [i];
         if (0 <= newX and newX < width and 0 <= newY and newY < height)
         {
            unsigned char red, green, blue;
            unsigned char red1, green1, blue1;
            input.get_pixel (newX, newY, red1, green1, blue1);
            input.get_pixel (x, y, red, green, blue);
            if (red == red1 and green == green1 and blue == blue1 and !visited [newY][newX])
            {
               s.push ({newY, newX});
            }
         }
      }
   }
}

int main()
{
   visited = new bool* [height];
   for (int i = 0 ; i < height ; i ++)
      visited [i] = new bool [width];
   if (!input)
   {
      printf("Error - Failed to open: input.bmp\n");
      return 1;
   }

   for (std::size_t y = 0; y < height; ++y)
   {
      for (std::size_t x = 0; x < width; ++x)
      {
         if (visited [y][x] != 1)
         {
            circles ++;
            dfs (y, x);
         }
      }
   }

   printf ("%d\n", circles - 1);

   for (int i = 0 ; i < height ; i ++)
      delete[] visited [i];
   delete[] visited;
}
