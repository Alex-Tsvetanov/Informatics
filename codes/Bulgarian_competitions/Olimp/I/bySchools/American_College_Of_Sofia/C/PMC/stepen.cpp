#include <iostream>
using namespace std;
int main(){
    
    int x, delimo=2, zapx, br=0, stepen=0, otg[100], i=0, j;
    cin >> x;
    zapx=x;
    for (delimo;delimo<x;delimo++)
    {
        for (x;x%delimo==0;x=x/delimo)
        {
            stepen+=1;
        }
        if (x==1)
        {
            br+=1;
            otg[i]=delimo; otg[i+1]=stepen;
            i+=2;            
        }
        stepen=0;
        x=zapx;
        
    }
    j=i;
    if (br>0) 
    {
        cout << br << endl;
        for (i=0;i<j;i=i+2)
        {
            cout << otg[i] << " " << otg[i+1] << endl;
        }
    }else cout << br;
    return 0;
}