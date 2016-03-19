#include <iostream>
using namespace std;

int main()
{
    int n,br=0;
    cin>>n;
    for (int i=n;i>=1;i--)
    {
        for (int j=n;j>=1;j--)
        {
                if ((n-i)*(n-j)==n) br++;
        }
    }
    cout<<br<<endl;
    
 return 0;
}