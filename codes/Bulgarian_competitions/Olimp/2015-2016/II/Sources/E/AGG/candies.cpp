#include <iostream>
using namespace std;
int main()
{
    int br=1,k1,k2,k3;
    cin>>k1>>k2>>k3;
    while (1==1)
    {
        if(br%4==3&&k3>0) {br++;k3--;}
        else
        {
            if(br%4==2||br%4==0&&k2>0) {br++;k2--;}
            else
            {
                if(br%4==1&&k1>0) {br++;k1--;}
                else break;
            }
        }
    }
    if(br>0) cout<<br-1;
    else cout<<"0"<<endl;
    return 0;
}
