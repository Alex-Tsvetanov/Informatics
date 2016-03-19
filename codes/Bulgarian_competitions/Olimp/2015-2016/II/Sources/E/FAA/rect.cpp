#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int n,br=0;
    cin>>n;
    for (int i=3,o=1;i*o<n;i+=2,o+=1)
    {
        if (n%i==o) br++;
    }
    cout<<br<<endl;
    return 0;
}
