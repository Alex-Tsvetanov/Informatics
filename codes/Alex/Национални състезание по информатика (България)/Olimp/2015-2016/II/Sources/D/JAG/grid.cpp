#include <iostream>
using namespace std;
int main()
{
 int arr[200][200];
 int br,segbr=0,broi=0,maxi,c,d,i,M,N,a,b;
 char bq,che;
 cin>>M>>N;
 br=M*N;
 for(b=0;b<=M-1;b++)
  for(a=0;a<=N-1;a++)
   {
   cin>>arr[a][b];
   }
  arr[0][0]=1;
  i=0;
  bq=0;
 do
 {
    for(b=0;b<=M;b++)
     for(a=0;a<=N;a++)
      for(d=0;d<=M;d++)
        for(c=0;c<=N;c++)
        {
  if(c>a&&c-a<=1&&d>b&&d-b<=1||c>a&&c-a<=1&&b>d&&b-d<=1||a>c&&a-c<=1&&b>d&&b-d<=1||a>c&&a-c<=1&&d>b&&d-b<=1) arr[c][d]=1;
        }
    for(b=0;b<=M;b++)
     for(a=0;a<=N;a++)
        {if(arr[a][b]==bq) arr[a][b]=1;}
   if(a>=maxi) maxi=a;
   if(b>=maxi) maxi=b;
   for(b=0;b<=M;b++)
    for(a=0;a<=N;a++)
   {
    if(arr[a][b]==bq) arr[a][b]=arr[a][b]+i;
   }
   i++;
   bq++;
   broi++;
 }
 while(broi<br/2);
 cout<<maxi-3;
return 0;
}
