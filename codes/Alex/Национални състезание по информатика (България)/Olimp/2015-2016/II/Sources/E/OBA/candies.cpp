#include<iostream>
using namespace std;
long long a,b,c,i,br=0;
int main()
{
    cin>>a>>b>>c;
    for (;;)
    {
        if (a>=1) {a--;br++;}
        else if (a==0) break;

        if (b>=1) {b--;br++;}
        else if (b==0) break;

        if (c>=1) {c--;br++;}
        else if (c==0) break;

        if (b>=1) {b--;br++;}
        else if (b==0) break;
    }
    cout<<br<<endl;
    return 0;
}
