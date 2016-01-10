#include<iostream>
using namespace std;
int main()
{
    int s,lv,st,s2,lv2,st2,s3,lv3,st3,a,b,c,c3,c2,sty2,sty3,sty;
    cin>>s>>lv>>st;
    cin>>s2>>lv2>>st2;
    cin>>a>>b;
    cin>>s3>>lv3>>st3;
    c=lv+st/10;
    sty=lv*100+st;

    c2=lv2+st2/10;
    sty2=lv2*100+st2;

    c3=lv3+st3/10;
    sty3=lv3*100+st3;
    if(s && lv && st < s2 && lv&& st2) if(s && lv && st< s3 && lv3 && st3) cout<<c<<" "<<sty;
    if(s2 && lv2 && st2< s && lv && st) if(s2 && lv2 && st2< s3 && lv3 && st3) cout<<c2<<" "<<sty2;
    if(s3 && lv3 && st3< s2 && lv2 && st2) if(s3 && lv3 && st3< s && lv && st) cout<<c3<<" "<<sty3;

    return 0;
}
