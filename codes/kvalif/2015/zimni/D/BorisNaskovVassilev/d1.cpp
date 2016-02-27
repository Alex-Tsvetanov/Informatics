#include <iostream>
using namespace std;
int main()
{
    long long chisla[20];
    int n;
    cin>>chisla[0]>>chisla[1]>>chisla[2]>>n;
    for(int i=3;i<n;i++)
    {
        chisla[i]=chisla[i-1]+chisla[i-2]+chisla[i-3];
    }
    cout<<chisla[n-1];
}
