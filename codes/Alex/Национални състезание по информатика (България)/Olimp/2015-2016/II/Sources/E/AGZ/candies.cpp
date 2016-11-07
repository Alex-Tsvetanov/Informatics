#include <iostream>
using namespace std;
int main()
{
    long long A,B,C,br=0;
    int i,j,l;
    cin>>A>>B>>C;
    i=A;
    j=B;
    l=C;
    while(i!=0 || j!=0 || l!=0)
    {
        i--;br++;
        j--;br++;
        l--;br++;
        j--;br++;
    }
    cout<<br<<endl;

    return 0;
}
