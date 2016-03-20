#include<iostream>
using namespace std;
short n,p,s,s1;
unsigned long long br;
void barza(short a)
{
    int i;
    if(a==n)
    {
            for(i=0;i<p;i++)
            {
                if(s1-i<0)break;
                br++;
                ///cout<<i<<" XX ";
            }
            return;
    }
    for(i=0; i<p; i++)
    {
        s1-=i;
        ///cout<<i<<" ";
        barza(a+1);
        ///cout<<"X ";
        s+=i;
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>p>>n>>s;
    s1=s;
    barza(1);
    cout<<br<<"\n";
    return 0;
}
