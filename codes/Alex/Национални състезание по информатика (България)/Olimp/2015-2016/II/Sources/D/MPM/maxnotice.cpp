#include<iostream>
using namespace std;
int main()
{
    long long l,h,n,i,s;
    struct note
    {
        long long x,y,dv,dh;
    };
    cin>>l>>h>>n;
    s=l*h;
    note notes[16];
    for(i=0;i<n;i++){cin>>notes[i].y>>notes[i].x>>notes[i].dh>>notes[i].dv;s=s-notes[i].dh*notes[i].dv;}
    cout<<s/2<<endl;
    return 0;
}
