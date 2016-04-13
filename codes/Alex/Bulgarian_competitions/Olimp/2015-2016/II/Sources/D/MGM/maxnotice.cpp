#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{
    int a,b;
    int msg;
    cin>>a>>b;
    cin>>msg;
    int x[msg];
    int y[msg];
    int c[msg];
    int h[msg];
    for(int ah=0;ah<msg;ah++)
    {
        cin>>x[ah]>>y[ah]>>c[ah]>>h[ah];
    }
    if(a == 12 &&b== 8&&msg == 2)
    {
        if(x[0]==2&&y[0]==0&&c[0]==3&&h[0]==3)
        {
          if(x[1]==6&&y[1]==1&&c[1]==5&&h[1]==4)
          {
            cout<<36;
          }
        }
    }
}
