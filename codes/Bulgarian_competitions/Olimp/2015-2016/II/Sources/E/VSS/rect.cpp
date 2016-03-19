#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
using namespace std;
int main()
{


    int n,br=0,a=3;
    cin>>n;

    for(int i=1;i<=a/2;i++)
    {
        if((n-i)%a==0)br++;
    a++;
    }

    cout<<br<<endl;



    return 0;
}
