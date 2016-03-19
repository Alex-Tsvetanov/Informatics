#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int k = 0;
    if((n - 1) % 3== 0)
    {
        for(int i = 0;i <= n;i += 4)
        {
            if((n - i) % 3 == 0)
            {
                k++;
            }
        }
        cout<<k<<endl;
    }
    else 
    cout<<k<<endl;
    return 0;
}