#include <iostream>
using namespace std;
int main()
{
    long long N,i,j,br=0;
    cin>>N;
    for(i=1;i<=N;i++)
        for(j=i;j<=N;j++)
        {
            if(((i+1)*j+(j+1)*i)==N) br++;
        }
        cout<<br<<endl;
    return 0;
}

