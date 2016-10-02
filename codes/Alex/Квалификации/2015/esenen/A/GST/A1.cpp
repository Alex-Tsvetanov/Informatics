#include<iostream>
#include<stdio.h>
#include<cmath>

using namespace std;
int main()
{
int N,x,y,x0,y0;

   cin>>N;
   cin>>x0>>y0;
 double xos,yos,z,degrees[N][3];
 int result[N][2],br=0;
   for(int i=0;i<N;i++)
   {
       cin>>x>>y;
       xos=x-x0;
       yos=y-y0;
       z=sqrt(xos*xos + yos*yos);
       xos/=z;
       yos/=z;
    degrees[i][0]=atan2(yos,xos);
 //  if(degrees[i][0]<0) degrees[i][0]+=-degrees[i][0]+3.1457;
    degrees[i][1]=i;

   }
   bool flag;
   do
   {
       flag=false;
       for(int i=0;i<N-1;i++)
       {
           if(degrees[i][0]>degrees[i+1][0])
           {
               flag=true;
               swap(degrees[i][0],degrees[i+1][0]);
                swap(degrees[i][1],degrees[i+1][1]);
           }
       }

   }while(flag);

   for(int i=0;i<N-1;i++)
   {
  // cout<<degrees[i][1]<<" "<<degrees[i+1][1]<<endl;
       if(degrees[i][1]<degrees[i+1][1])
       {
           result[br][0]=degrees[i][1];
           result[br][1]=degrees[i+1][1];
           result[br][2]=degrees[i+1][0]-degrees[i][0];
           br++;
       }
   }

  /* do
   {
       flag=false;
       for(int i=0;i<br-1;i++)
       {
           cout<<result[i][2]<<" "<<result[i+1][2]<<endl;
           if(result[i][2]>result[i+1][2])
           {
               flag=true;
               swap(result[i][0],result[i+1][0]);
                swap(result[i][1],result[i+1][1]);
                swap(result[i][2],result[i+1][2]);
           }
       }

   }while(flag);*/

for(int i=0;i<br;i++)
{
    cout<<result[i][0]+1<<" "<<result[i][1]+1<<endl;
}
    return 0;
}
//y,x
/*
4
0 0
1 0
1 1
0 1
-1 0


20
1 1
1 2
1 2
1 2
1 2
1 2
1 2
1 2
1 2
1 2
1 2
1 2
1 2
1 2
1 2
1 2
1 2
1 2
1 2
1 2
1 2

*/
