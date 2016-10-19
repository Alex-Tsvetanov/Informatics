#include "bitmap_image.hpp"

int main()
{
   bitmap_image image(200,200);

   // set background to orange
   image.set_all_channels(255,150,50);

   image_drawer draw(image);

   draw.pen_width(3);
   draw.pen_color(255,0,0);
   draw.circle(image.width() / 2, image.height() / 2,50);

   draw.pen_width(1);
   draw.pen_color(0,0,255);
   draw.rectangle(50,50,150,150);

   image.save_image("output.bmp");

   return 0;
}
