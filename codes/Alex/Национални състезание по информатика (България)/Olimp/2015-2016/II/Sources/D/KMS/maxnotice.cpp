#include<iostream>
#define MAXLNH 120
#define MAXHIGH 80
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
        for(i=x;i<y+m;i++)
            for(j=y;j<y+n;j++)
                if(a[i][j]||i>=plate.h||j>plate.l) return 0;
        return 1;
    }

int main()
{
    int i, j, k, u, v;
    int n, br=0;
    cin>>plate.l>>plate.h;
    for(i=0;i<plate.h;i++)
        for(j=0;j<plate.l;j++)
        a[i][j]=0;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>notices[i].X1>>notices[i].Y1>>notices[i].l>>notices[i].h;
        notices[i].X2=notices[i].X1+notices[i].l-1;
        notices[i].Y2=notices[i].Y1+notices[i].h-1;
    }
    cin>>u>>v;
    for(k=0;k<n;k++)
        for(i=notices[k].Y1;i<=notices[k].Y2; i++)

}
