///Simeon Atanasov Atanasov 7a MG
///NOI-2 2016 C1. Virus
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
int n;

int main ()
{
    cin >> n;
    int q=n/2;
    if(!n%2)q++;
    cout << q << endl;
    /**if(n<500)
    {
        cout << q;
        cout << 1;
        for(i=2;i<=q;i++)
        {
            cout << " " << i;
        }
        cout << q;
        cout << q/2+1;
        for(i=q/2+2;i<n-1;i++)cout << " " << i;

    }**/
    return 0;
}
