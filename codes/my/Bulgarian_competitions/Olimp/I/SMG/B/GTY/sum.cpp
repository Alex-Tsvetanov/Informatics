#include<iostream>

using namespace std;

long long bs(int N,int a)
{
    if(a==1)return N;
    if(a<1)return 1;
    return bs(N,a/2)*bs(N,(a-a/2));
}
int pow2[16];
int res[4000];
int main()
{
    for(int i=0;i<=11;i++)pow2[i]=bs(2,i);

    int N;
    cin>>N;
    if(N==1){cout<<1;return 0;}
    int br=0, sb=2;
    if(N%2==1)N--;
    N/=2;
    int red[4000]={0,1,2,4,6,9,12,16,20,25,30};
    for(int i=5;i<=3000;i++)
    {
        if(red[i-1]-red[i-2]==red[i-2]-red[i-3])red[i]=red[i-1]+(red[i-1]-red[i-2])+1;
        else red[i]=red[i-1]+(red[i-1]-red[i-2]);
    }

    cout<<red[N+1]<<endl;
    return 0;
}
