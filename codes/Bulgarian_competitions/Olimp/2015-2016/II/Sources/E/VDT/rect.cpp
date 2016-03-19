#include<iostream>
using namespace std;
int main()
{
    long x,y,kl,rectcount=0;//x-дължина; у-ширина
    cin>>kl;
    for(x=1;x<=1000;x++)
    {
        for(y=2;y<=1000;y++)
        {
            if(((x*y)+((y-1)*(x+1))==kl) || (x*y)+((x-1)*(y+1))==kl)  rectcount++;
        }
        
    }
    cout<<rectcount/4<<endl;
    return 0;
}