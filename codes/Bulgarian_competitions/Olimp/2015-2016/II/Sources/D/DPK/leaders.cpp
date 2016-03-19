#include<iostream>
using namespace std;
int main ()
{
    int max,n;
    cin >> n;
    int A[n];
    for (int i = 0;i<n;i++)
    {
        cin >> A[i];
        max = A[0];
        if (max<A[i]) max = A[i];
    }
    cout<<max;
    return 0;
}
