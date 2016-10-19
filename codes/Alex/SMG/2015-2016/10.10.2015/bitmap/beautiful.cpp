#include "bitmap_image.hpp"
#include <iostream>
#include <vector>

using namespace std;

int ind = 2;

void addOne (vector <int*>& arr);
void minusOne (vector <int*>& arr);

void (*automatic) (vector <int*>&) = minusOne;

void minusOne (vector <int*>& arr)
{
   cout << (*(arr [0])) << ":" << (*(arr [1])) << ":" << (*(arr [2])) << "  " << ind << "\n"; 
   (*arr [ind]) --;
   for (int i = ind - 1 ; i >= 0 ; i --)
      if ((*arr [i + 1]) <= -1) (*arr [i + 1]) = 0, (*arr [i]) = (*arr [i]) - 1;
   if ((*arr [0]) <= -1)
   {
      (*arr [0]) = 0;
      (*arr [1]) = 0;
      (*arr [2]) = 0;
      automatic = addOne;
      ind --;
      ind += 3;
      ind %= 3;
   }
   cout << *arr [0] << ":" << *arr [1] << ":" << *arr [2] << "  " << ind << "|\n"; 
}

void addOne (vector <int*>& arr)
{
   cout << *arr [0] << ":" << *arr [1] << ":" << *arr [2] << "  " << ind << "\n"; 
   (*arr [ind]) ++;
   for (int i = ind - 1 ; i >= 0 ; i --)
      if ((*arr [i - 1]) >= 256) (*arr [i - 1]) = 0, (*arr [i]) = (*arr [i]) + 1;
   if ((*arr [0]) >= 256)
   {
      (*arr [0]) = 256;
      (*arr [1]) = 256;
      (*arr [2]) = 256;
      automatic = minusOne;
      ind --;
      ind += 3;
      ind %= 3;
   }
   cout << *arr [0] << ":" << *arr [1] << ":" << *arr [2] << "  " << ind << "\n"; 
}

bool NextTone (vector <int*> arr, int tones)
{
   for (int i = 0 ; i < tones ; i ++)
      automatic (arr);
   cout << *arr [0] << ":" << *arr [1] << ":" << *arr [2] << "\n"; 
   return true;
}
void Swaping (int& red, int& green, int& blue)
{
   int tmp = red;
   red = green;
   green = blue;
   blue = tmp;
}
int main()
{
   const int size = 1250;
   bitmap_image image(size,size);

   image.set_all_channels(0,0,0);

   image_drawer draw(image);

   int red = 255, green = 255, blue = 255, radius = 1;
   ind = 1;
   automatic = minusOne;
   int plusTones = 1;
   int pen_width = 2;
   int max_radius = ((min (image.width (), image.height ()) - (pen_width - 1))/ 2) + 1;
   do
   {
      cout << red << ":" << green << ":" << blue << " " << radius << "\n"; 
      draw.pen_width(pen_width);
      draw.pen_color(red,green,blue);
      draw.circle(image.width() / 2, image.height() / 2, radius);
      radius += 1;
      //Swaping (red, green, blue);
      plusTones += 0;
   }
   while (radius < max_radius and NextTone ({&red, &green, &blue}, plusTones));
   image.save_image("output.bmp");


   return 0;
}
