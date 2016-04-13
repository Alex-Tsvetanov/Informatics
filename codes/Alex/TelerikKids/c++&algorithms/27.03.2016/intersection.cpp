#include <iostream>
#include <stdio.h>
#include <math.h>

// Returns 1 if the lines intersect, otherwise 0. In addition, if the lines
// intersect the intersection point may be stored in the floats i_x and i_y.
char get_line_intersection(float p0_x, float p0_y, float p1_x, float p1_y,
    float p2_x, float p2_y, float p3_x, float p3_y, float *i_x, float *i_y)
{
    float s1_x, s1_y, s2_x, s2_y;
    s1_x = p1_x - p0_x;     s1_y = p1_y - p0_y;
    s2_x = p3_x - p2_x;     s2_y = p3_y - p2_y;

    float s, t;
    s = (-s1_y * (p0_x - p2_x) + s1_x * (p0_y - p2_y)) / (-s2_x * s1_y + s1_x * s2_y);
    t = ( s2_x * (p0_y - p2_y) - s2_y * (p0_x - p2_x)) / (-s2_x * s1_y + s1_x * s2_y);

    if (s >= 0 && s <= 1 && t >= 0 && t <= 1)
    {
        // Collision detected
        if (i_x != NULL)
            *i_x = p0_x + (t * s1_x);
        if (i_y != NULL)
            *i_y = p0_y + (t * s1_y);
        return 1;
    }

    return 0; // No collision
}

int main ()
{
    float m1, c1, m2, c2;
    float l1x1, l1y1, l1x2, l1y2;
    float l2x1, l2y1, l2x2, l2y2;
    float intersection_X, intersection_Y;
    int nRet;

    std::cout << "Program to find the intersection point of two line segments:\n";

    std::cout << "Enter Line1 - X1: ";
    std::cin >> l1x1;

    std::cout << "Enter Line1 - Y1: ";
    std::cin >> l1y1;

    std::cout << "Enter Line1 - X2: ";
    std::cin >> l1x2;

    std::cout << "Enter Line1 - Y2: ";
    std::cin >> l1y2;

    std::cout << "Enter Line2 - X1: ";
    std::cin >> l2x1;

    std::cout << "Enter Line2 - Y1: ";
    std::cin >> l2y1;

    std::cout << "Enter Line2 - X2: ";
    std::cin >> l2x2;

    std::cout << "Enter Line2 - Y2: ";
    std::cin >> l2y2;

    nRet = get_line_intersection (l1x1, l1y1, l1x2, l1y2, l2x1, l2y1, l2x2, l2y2, &intersection_X, &intersection_Y);

    if(nRet == 0)
        printf("The two line segments do not intersect each other");
    else
        printf("The two line segments intersect each other at %.2f, %.2f", intersection_X, intersection_Y);
}
