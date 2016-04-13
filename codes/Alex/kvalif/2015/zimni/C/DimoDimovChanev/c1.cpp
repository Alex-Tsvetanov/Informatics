#include <iostream>
#define _USE_MATH_DEFINES
#include <cmath>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    for(int i = 0; i<n; i++)
    {
        int k;
        cin>>k;
        int res = 0;
        if(k == 1)
        {
            cout<<1<<" ";
            continue;
        }
        for(int j = 2; j*j<k; j++)
        {
            if(k%j==0)
                res++;
        }
        if(ceil(sqrt(k)) == floor(sqrt(k)))
        {
            cout<<(res+2)*2;
        }
        else
        {
            cout<<(res+1)*2;
        }
        cout<<" ";
    }
    cout<<endl;
    return 0;
}
