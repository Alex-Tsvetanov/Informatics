#include<iostream>
#include<string>
using namespace std;
string vhod;
int main()
{
    int A=0, B=0, X, i=0;
    cin>>vhod;
    int len=vhod.size();
    if(vhod[0]!='X')
    {
        for(i=0; vhod[i]!='+'; i++)
        {
            A=A*10+(vhod[i]-'0');
        }
        i+=3;
        for(; i<len; i++)
        {
            B=B*10+(vhod[i]-'0');
        }
    }
    else
    {
        i+=2;
        for(; vhod[i]!='='; i++)
        {
            A=A*10+(vhod[i]-'0');
        }
        i++;
        for(; i<len; i++)
        {
            B=B*10+(vhod[i]-'0');
        }
    }
    cout<<B-A<<endl;
    return 0;
}
