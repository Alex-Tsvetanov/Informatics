#include<iostream>
#include<algorithm>
using namespace std;

int p,n,s,res=0;

void rec (int sum,int pos)
{   //cout<<sum<<" "<<pos<<endl;
    //cout<<pos<<" ";
    if(sum>=s){/*cout<<"NO"<<endl;*/return;}
    if(pos==n)
    {   if(sum<s){res++;/*cout<<"+1"<<endl;*/}
        return;
    }
    for(int i=0;i<min(s-sum,p);i++)
        {rec(sum+i,pos+1);}
}

int main()
{   cin>>p>>n>>s;
    rec(0,0);
    cout<<res<<endl;


    return 0;
}
