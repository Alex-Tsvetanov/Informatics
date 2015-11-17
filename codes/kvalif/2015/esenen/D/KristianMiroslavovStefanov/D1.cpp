#include <iostream>
using namespace std;
int main()
{
    int S, P, j;
    cin>>S;
    P=2*S+2;
    for(int i=1; i<=(S+1)/2; i++)
        if (S%i==0 and i<=S/i)
        {
            j=S/i;
            if ((2*i+2*j)<P)
                P=2*i+2*j;
        }

    cout <<P;

    return 0;
}
