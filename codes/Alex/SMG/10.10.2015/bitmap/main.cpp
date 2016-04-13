#include <cstdio>
#include "bitmap_image.hpp"

int main()
{
   bitmap_image  input("./test18_color_maps.bmp");

   if (!input)
   {
      printf("Error - Failed to open: input.bmp\n");
      return 1;
   }

   unsigned char red;
   unsigned char green;
   unsigned char blue;

   const unsigned int height = input.height();
   const unsigned int width  = input.width();
   bitmap_image output(width, height);

   for (std::size_t y = 0; y < height; ++y)
   {
      for (std::size_t x = 0; x < width; ++x)
      {
          input.get_pixel (x, y, red, green, blue);
         output.set_pixel (x, y, 255 - red, 255 - green, 255 - blue);
      }
   }

   output.save_image ("./output.bmp");
   return 0;
}
