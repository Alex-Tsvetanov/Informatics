#include<iostream>
#include<cstring>
using namespace std;
char va[100],vb[100],a[100],b[100],c[100];
int an,bn,cn,n;
int main()
{
    int i,carry='0';
    cin>>va>>vb;an=strlen(va);bn=strlen(vb);
    for(i=0;i<an;++i){a[i]=va[an-1-i];}for(i=0;i<bn;++i){b[i]=vb[bn-1-i];}n=an;
    if(an>bn){for(i=bn;i<an;++i){b[i]='0';}}if(bn>an){for(i=an;i<bn;++i){a[i]='0';}n=bn;}
    a[n]='0';b[n]='0';++n;
    for(i=0;i<n;++i)
    {
        if(a[i]=='?'||b[i]=='?'||carry=='?'){c[i]='?';}
        else{c[i]=(a[i]-'0')^(b[i]-'0')^(carry-'0')+'0';}
        if(((a[i]=='1')+(b[i]=='1')+(carry=='1'))>1){carry='1';}
        else
        {
            if(((a[i]=='0')+(b[i]=='0')+(carry=='0'))>1){carry='0';}
            else{carry='?';}
        }
    }
    for(i=n-1;c[i]=='0';--i){}
    for(;i>=0;--i){cout<<c[i];}
    cout<<endl;
    return 0;
}
