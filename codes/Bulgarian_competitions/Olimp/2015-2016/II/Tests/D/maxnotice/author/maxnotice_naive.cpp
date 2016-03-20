// Task Maxnotice
// Author Plamenka Hristova
#include <iostream>
#define MAXLNH  90
#define MAXHIGH 55
using namespace std;
typedef struct
        {
         int X1, Y1;
         int X2, Y2;
         int l, h;
        }
        rect;

int a[MAXHIGH][MAXLNH];
rect notices[20];
rect plate;

int IsFree(int x, int y, int n, int m)
    {
     int i, j;
     for(i=x; i<x+m; i++)
        for(j=y; j<y+n; j++)
           if(a[i][j]||i>=plate.h||j>=plate.l) return 0;
     return 1;
    }


int main()
{
    int i,j,k, u, v,s;
    int n, max=0;

    cin >> plate.l >> plate.h;
    // Запълваме масива А с нули
    for(i=0; i<plate.h; i++)
       for(j=0; j<plate.l; j++)
           a[i][j]=0;
    cin >> n;
    for(i=0; i<n; i++)
        {
         cin>>notices[i].X1>>notices[i].Y1>>notices[i].l>>notices[i].h;
    // Кооодринати на долен десен ьгъл
         notices[i].X2=notices[i].X1+notices[i].l-1;
         notices[i].Y2=notices[i].Y1+notices[i].h-1;
        }

    // Записваме 1 в клетките, в които има поставена бележка
    for(k=0; k<n; k++)
        for(i=notices[k].Y1; i<=notices[k].Y2; i++)
           for(j=notices[k].X1; j<=notices[k].X2; j++)
               a[i][j]=1;
    //
    for(i=0; i<plate.h; i++)
        for(j=0; j<plate.l; j++)
          for(u=1; u<=plate.l;u++)
             for(v=1; v<=plate.h;v++)
                if ((a[i][j]== 0) && (IsFree(i, j, u, v)==1) )
                    {
                        s=u*v;
                        if(s>max) max=s;
                    }
     cout << max << endl;
    return 0;
}
