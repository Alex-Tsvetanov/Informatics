#include <iostream>
#include <algorithm>
using namespace std;
int main ()
{
    int n,a,b,br=0;
    cin>>n;
    for(a=0;a<n;a++)
        for(b=0;b<n;b++)
    {
        if(a*b==n)
            br++;
    }
    cout<<br;
}
