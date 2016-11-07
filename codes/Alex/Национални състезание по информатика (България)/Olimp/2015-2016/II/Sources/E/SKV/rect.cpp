#include<iostream>
using namespace std;
int main()
{
    int N,i=3,br=0,b;
    cin>>N;
    if((N-1)%3==0)br++;
    for(b=0;b<100;b++)
    {
        i++;
        if((N-2)%i==0)br++;
    }
    cout<<br<<endl;
    return 0;
}
