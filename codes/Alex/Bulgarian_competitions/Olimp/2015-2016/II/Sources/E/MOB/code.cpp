#include<iostream>
using namespace std;
string s,a,m;
int main()
{
    long long i,n,br=0,r=0,broi1=0,broi2=0;
    char c;
    getline(cin,s,'.');
    for( i=0; i<s.size();)
    {
        c=s[i];
        while(s[i]==c)
        {
            i++;
            br++;
        }
        if(br>1)
        {
            while(br!=0)
            {m+=br%10;br/=10;}
            a+=m;
            a+=c;
        }
        if(br==1)
        {
            a+=c;
        }
        br=0;
        m="";
    }
    for(int j=1; j<s.size(); j++)broi1++;
    for(int j=1; j<a.size(); j++)broi2++;
    if(broi2>broi1)swap(broi2,broi1);
    r=broi1-broi2;
    cout<<r<<endl;
    return 0;
}
