#include <iostream>

using namespace std;

int main ()
{
    int a1,b1,a2,b2,a3,b3;
    int S,b,ra1,rb1,ra2,rb2;
    int h,w;
    int x1,x2;
    int y;

    cin >> a1 >> b1;
    S = a1 * b1;
    cin >> a2 >> b2;
    S = S + a2 * b2;
    cin >> a3 >> b3;
    S = S + a3 * b3;

    int n;
    for (n = 0 ; n < 6 ; n ++)
    {
        if (n == 0)
        {
            h = a1;
            b = b1;
            ra1 = a2;
            rb1 = b2;
            ra2 = a3;
            rb2 = b3;
        }
        if (n == 1)
        {
            h = b1;
            b = a1;
            ra1 = a2;
            rb1 = b2;
            ra2 = a3;
            rb2 = b3;
        }
        if (n == 2)
        {
            h = a2;
            b = b2;
            ra1 = a1;
            rb1 = b1;
            ra2 = a3;
            rb2 = b3;
        }
        if (n == 3)
        {
            h = b2;
            b = a2;
            ra1 = a1;
            rb1 = b1;
            ra2 = a3;
            rb2 = b3;
        }
        if (n == 4)
        {
            h = a3;
            b = b3;
            ra1 = a1;
            rb1 = b1;
            ra2 = a2;
            rb2 = b2;
        }
        if (n == 5)
        {
            h = b3;
            b = a3;
            ra1=a1;
            rb1 = b1;
            ra2 = a2;
            rb2 = b2;
        }
        if (S % h == 0)
        {
            w = S / h;
            y = -1;
            if (ra1 == h and ra2 == h)
            {
                x1 = rb1;
                x2 = rb1 + rb2;
                break;
            }
            if (ra1 == h and rb2 == h)
            {
                x1 = rb1;
                x2 = rb1 + ra2;
                break;
            }
            if (rb1 == h and ra2 == h)
            {
                x1 = ra1;
                x2 = ra1+rb2;
                break;
            }
            if (rb1 == h and rb2 == h)
            {
                x1 = ra1;
                x2 = ra1 + ra2;
                break;
            }
            x1 = w-b;
            x2 = -1;
            if (ra1 == x1 and ra2 == x1 and rb1 + rb2 == h)
            {
                y = rb1;
                break;
            }
            if (ra1 == x1 and rb2 == x1 and rb1 + ra2 == h)
            {
                y = rb1;
                break;
            }
            if (rb1 == x1 and ra2 == x1 and ra1 + rb2 == h)
            {
                y = ra1;
                break;
            }
            if (rb1 == x1 and rb2 == x1 and ra1 + ra2 == h)
            {
                y = ra1;
                break;
            }
        }
    }

    if (n >= 6) return 0;

    for (int i = 0 ; i <= h ; i ++)
    {
        for (int j = 0 ; j <= w ; j ++)
            if (i == 0 or i == h or 
                j == 0 or j == w or
                j == x1 or j == x2 or                      
               (i == y and j <= x1) or
               (i <= y and j == x1))
            {
                cout << '.';
                if (j < w)
                    cout << ' ';
            }
            else 
                cout << "  " ;
        cout << '\n';
    }
}

