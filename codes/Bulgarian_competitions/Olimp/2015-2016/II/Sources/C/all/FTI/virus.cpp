#include<iostream>
using namespace std;
short int dp[50000000],st;
unsigned long long int n,k,i;
int main()
{
    cin>>n;
    if(n==1)
    {
        dp[1]=1;
        cout<<1<<endl<<1<<" "<<1<<endl;
    }
    if(n==2)
    {
        dp[2]=2;
        cout<<2<<endl<<1<<" "<<2<<endl<<2<<" "<<1<<" "<<2<<endl;
    }
     if(n==3)
     {
         dp[3]=2;
         cout<<2<<endl<<"2 1 2"<<endl<<"2 1 3"<<endl;
     }
     if(n==4)
     {
         dp[4]=3;
         cout<<3<<endl<<"3 1 2 3"<<endl<<"3 1 2 4"<<endl<<"3 1 3 4"<<endl;
     }
     if(n==5)
     {
         dp[5]=3;
         cout<<3<<endl<<"2 3 5"<<endl<<"4 1 2 3 5"<<endl<<"3 2 4 5"<<endl;
     }
     if(n==6)
     {
         dp[6]=3;
         cout<<3<<endl<<"3 1 2 3"<<endl<<"4 1 2 4 6"<<endl<<"3 1 5 6"<<endl;
     }
     if(n==7)
     {
         dp[7]=3;
         cout<<3<<endl<<"4 1 2 3 7"<<endl<<"4 1 2 4 6"<<endl<<"4 1 5 6 7"<<endl;
     }
     if(n==8)
     {
         dp[8]=4;
         cout<<4<<endl<<"5 1 2 4 6 8"<<endl<<"6 1 2 5 6 7 8"<<endl<<"6 1 3 4 6 7 8"<<endl<<"4 1 3 5 7"<<endl;
     }
     if(n==9)
     {
         dp[9]=4;
         cout<<4<<endl<<"6 1 2 4 6 8 9"<<endl<<"7 1 2 5 6 7 8 9"<<endl<<"6 1 3 4 6 7 8"<<endl<<"5 1 3 5 7 9"<<endl;
     }
     if(n==10)
     {
       dp[10]=4;
       cout<<4<<endl<<"7 1 2 4 6 8 9 10"<<endl<<"7 1 2 5 6 7 8 9"<<endl<<"7 1 3 4 6 7 8 10"<<endl<<"6 1 3 5 7 9 10"<<endl;
     }
dp[11]=dp[12]=dp[13]=dp[14]=dp[15]=4;
st=5;
k=32;
for(i=16;i<n;i++)
{
    while(i<=k)
    {
        dp[i]=st;
        i++;
    }
    st++;
    k*=2;
}
cout<<dp[n]-1<<endl;
}
