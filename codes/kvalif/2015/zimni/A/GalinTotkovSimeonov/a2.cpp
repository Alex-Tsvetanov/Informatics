#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
  long long m,n,a,b,kek=0,br=0;
  bool flag;
  cin>>m>>n;
  long A[2*n];
  cin>>a>>b;
  A[0]=a;
  A[1]=b;
  kek=1;
int beg,endd;
  for(long long i=1;i<n;i++)
  {
      cin>>a>>b;
      endd=kek;
      beg=0;
      for(int y=0;y<kek;y+=2)
      {
         if(a<=A[y])beg=y;
         if(b>=A[y+1])endd=y;
         if(A[y]>=a and A[y+1]<=b)
         {
          A[y]=0;
          A[y+1]=0;
         }
      }
      if(beg==endd){

        kek+=2;
        A[kek]=a;
        A[kek+1]=b;
      }else{
        //  cout<<beg<<" "<<endd<<endl;
          A[beg]=a;
          A[beg+1]=b;

      for(int y=beg+1;y<endd;y++)
      {
          A[y]=0;
          A[y+1]=0;
      }

      }

      do{
        flag=true;
        for(int y=0;y<kek;y++)
        {
            if(A[y]>A[y+1]){swap(A[y],A[y+1]);flag=false;}
        }
      }while(flag);
  }
  for(int i=0;i<kek;i+=2)
  {
     if(A[i]!=0 and A[i+1]!=0)br++;
  }
  cout<<br<<endl;
    return 0;
}
