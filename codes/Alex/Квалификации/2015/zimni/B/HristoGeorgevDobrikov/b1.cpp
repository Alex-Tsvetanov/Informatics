#include<iostream>
using namespace std;
int main ()
{
    int M1,N1,m1,n1,z=0,x=0;
    cin>>M1>>N1>>m1>>n1;
    int red1[M1][N1],sum[10000],d=0;
    for(int a=0; a++; a<10000)
        sum[a]=0;
    for(int a=0; a<M1; a++)
        for(int b=0; b<N1; b++)
            cin>>red1[a][b];
    for(int a=0; a<M1; a++)
    {
        for(int b=0; b<N1; b++)
            {
                x=-1;
            z=-1;
            d++;
            while(x<=m1)
            {
                if(x+1>M1){
               x=m1;
                }
                else x++;
               while(z<=n1)
               {
                   if(z+1>N1){
                 z=n1;
                   }
                 else
                    z++;

                 sum[d]=sum[d]+red1[a+x][b+z] ;
               }

                 }
            }

    }
int max1=sum[1];
for(int a=0;a<d;a++)
{
    if(max1<sum[a] and sum[a]<30000)
        max1=sum[a];
}
    cout<<max1;
    return 0;
}
