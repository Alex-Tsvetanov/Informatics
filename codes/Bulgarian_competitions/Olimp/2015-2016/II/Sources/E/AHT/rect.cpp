#include <iostream>
using namespace std;
int main ()
    {
    long long N,a,b,br=0,i,i1;
    cin>>N;
    for(a=1;a<N;a++)
    for(b=1;b<N;b++)
    if((a+1)*b+(b+1)*a==N)br++;
    if(br%2==0)
    cout<<br/2<<endl;
    else cout<<br/2+1<<endl;
    return 0;
    }
