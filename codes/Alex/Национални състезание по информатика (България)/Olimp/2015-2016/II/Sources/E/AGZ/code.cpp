#include <iostream>
using namespace std;
int main()
{
    char a;
    int br=0,br1=0,br2=0,k;
    while(a!='.')
    {
        cin>>a;br++;
        k=a;
        if(a==k)
        br1++;
        if(br==1)cout<<"0"<<endl;
        else cout<<br-(br1+1)<<endl;break;
    }


    return 0;
}
