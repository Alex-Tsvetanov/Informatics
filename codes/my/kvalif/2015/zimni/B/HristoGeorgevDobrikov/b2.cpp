#include<iostream>
#include<cstdlib>
using namespace std;
int main ()
{
    int x,y,T,r,zdravi=0;
    cin>>x>>y>>T;
    int pole[x][y],a,b,c,d,e;
    for(a=0; a<x; a++)
    {
        for(b=0; b<y; b++)
            pole[a][b]=0;
    }
    a=0;
    while(a<2)
    {
        a++;
        cin>>c>>d;
        pole[c][d]=1;
    }
    for(c=1; c<=T; c++)
    {
        for(a=0; a<x; a++)
        {
            for(b=0; b<y; b++)
            {
                if(pole[a][b]==1)
                {
                    if(a+1<x){
                        pole[a+1][b]=2;
                    }
                    if(a-1>=0){
                        pole[a-1][b]=2;
                    }
                    if(b+1<y){
                        pole[a][b+1]=2;
                    }
                    if(b-1>=0){
                        pole[a][b-1]=2;
                    }
                }
            }
        }
        for(d=0; d<x; d<y)
        {
            for(e=0; e<y; e++)
            {
                if(pole[d][e]==2)
                {
                    pole[d][e]=1;
                }
            }
        }
        }
    return 0;
}

