#include<iostream>
using namespace std;
int b[3][1000];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int k;
    cin>>k;
    int x,y,br=0,xi=1,yi=2;
    x=3;y=5;
    while(x<=k)
    {
        while(y<=k)
        {
            y=xi*(yi+1)+yi*(xi+1);
            if(xi<yi) y=y-2*xi;
            else y=y-2*yi+1;
            if(y==k)
            {
                br++;
                b[1][br]=xi;
                b[2][br]=yi;
                break;
            }
            yi++;
        }

        xi++;yi=2;
        x=xi+1+2*xi;
        if(xi<yi) x=x-2*xi;
        else x=x-2*yi+1;
        if(x==k)
        {
            br++;
            b[1][br]=xi;
            b[2][br]=yi;
            break;
        }

    }
    cout<<br<<endl;
    for(int i=1;i<=br;i++)
    {
        cout<<b[1][br]<<" "<<b[2][br]<<endl;
    }
    return 0;
}
