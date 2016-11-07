#include<iostream>
#include<vector>
using namespace std;
vector<long long> otgX,otgY;
int main(){
int k;
cin>>k;
//cout<<sqrt(1 000 000 000);
for(long long y=1;1;y++)
{
    for(long long x=1;1;x++)
    {

        long long zdravi;
        if(y<x)
        {
                zdravi=(x*(y+1)+y*(x+1))-(y+y);
                if( zdravi==k){
               // cout<<"DA "<<x<<" "<<y<<endl;
                otgX.push_back(x);
                otgY.push_back(y);
                }
        }
        else
        {
           zdravi=(x*(y+1)+y*(x+1))-(x+(x-1));
            if(zdravi==k){
               // cout<<"DA "<<x<<" "<<y<<endl;
                otgX.push_back(x);
                otgY.push_back(y);
            }
        }
        if(x==1 && zdravi>k)
        {
                int t=otgX.size();
                cout<<t<<endl;
                for(int i=0;i<t;i++)
                {
                    cout<<otgY[i]<<" "<<otgX[i]<<endl;
                }
            return 0;
        }
        if(zdravi>k)
            break;
    }
}
int t=otgX.size();
cout<<t<<endl;
for(int i=0;i<t;i++)
{
    cout<<otgY[i]<<" "<<otgX[i]<<endl;
}
return 0;
}
