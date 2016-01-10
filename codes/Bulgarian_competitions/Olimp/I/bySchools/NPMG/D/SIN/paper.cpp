#include<iostream>
using namespace std;
int main ( )
{
    bool xnech=true,ynech=true;
    int x,y,br;
    cin >> x >> y;
    if(y>x)
        swap(x,y);
    while(x!=1){
        if(x%2!=0)
            xnech=true;
        x/=2;
        if(xnech)
            x+=1;
        ++br;
    }
    while(y!=1){
        if(y%2!=0)
            ynech=true;
        y/=2;
        if(ynech)
            y+=1;
        ++br;
    }
    cout << br;
    return 0;
}
