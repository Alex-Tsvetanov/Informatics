#include <iostream>
using namespace std;
int main()
{
    string t;
    int i,sz,brp=0,brz=0,brsz=0;
    cin>>t;
    sz=t.size()-1;
    for(i=0;i<sz;i++)
    {
        if(t[i]==t[i+1])
        {
            brp++;
            if(brp==1) brsz=1;
            else if(brp==10) brsz=2;
            else if(brp==100) brsz=3;
            else if(brp==1000) brsz=4;
            else if(brp==10000) brsz=5;
            else if(brp==100000) brsz=6;
            else if(brp==1000000) brsz=7;
        }
        else {brp=0;brz=brz+brsz+1;cout<<brsz<<" ";brsz=0;};
    }
    cout<<sz-brz<<endl;
	return 0;
}
