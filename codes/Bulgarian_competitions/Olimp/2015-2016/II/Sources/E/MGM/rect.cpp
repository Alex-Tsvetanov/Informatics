#include <iostream>
using namespace std;
int main()
{
    long long n, br=0;
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(i*(j+1)+(i+1)*j==n&&i>=j) br++;
        }
    }
    cout<<br<<endl;
    return 0;
}
