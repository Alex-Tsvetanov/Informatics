#include <iostream>
using namespace std;
int main()
{
    long long a,b,c,br=0;
    cin>>a>>b>>c;
    for(;;)
    {
        a--;
        br++;
        if(a==-1) {br--;break;}
        b--;
        br++;
        if(b==-1) {br--;break;}
        c--;
        br++;
        if(c==-1) {br--;break;}
        b--;
        br++;
        if(b==-1) {br--;break;}
    }
    cout<<br<<endl;
}
