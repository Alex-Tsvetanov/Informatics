#include <iostream>
using namespace std;
int main()
{
    long long N,br=0;
    cin>>N;
    int i=1,j,l;
    for (l=1; l<=N; l++)
        for(j=1; j<=N; j++)
            if(i*4+l*3+j*2==N&&N-(i*4+l*3+j*2)==0)br++;
            if(N==4){cout<<"1"<<endl;}
            if(br==0)cout<<"0"<<endl;
            else cout<<br<<endl;

    return 0;
}
