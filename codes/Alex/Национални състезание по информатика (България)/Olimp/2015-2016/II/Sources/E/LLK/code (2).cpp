#include<iostream>
using namespace std;
int main()
{
    int br=0,br1=1,d;
    char j,i;
    cin>>j;
    while(j!='.')
    {
        i=j;
        cin>>j;
        if(i==j)
        {
            br1++;
        }
        else if(br1>1)
        {
            if(br1<=9){d=2;}
            else if(br1>9 && br1<100){d=3;}
            else if(br1>99 && br1<1000){d=4;}
            else if(br1>999 && br1<10000){d=5;}
            else if(br1>9999 && br1<100000){d=6;}
            else if(br1>99999 && br1<1000000){d=7;}
            br=br+br1-d;
            br1=1;
        }
    }
    cout<<br<<endl;
    return 0;
}
