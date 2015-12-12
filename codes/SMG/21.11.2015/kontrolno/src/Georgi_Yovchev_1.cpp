#include<iostream>

using namespace std;

void c(int a)
{
    if(a<10)
    {
        cout<<0<<a;
    }else
    {
        cout<<a;
    }

}

int sto(string a)
{
    return (a[0]-'0')*10 + (a[1]-'0');
}
int n(int a)
{
    if(a<0)return 24+a;
    return a;
}
int main()
{
    int h1,m1,h2,m2;
    string a;
    cin>>a;
    string b="";
    b+=a[0];
    b+=a[1];
    h1=sto(b);
    b="";
    b+=a[3];
    b+=a[4];
    m1=sto(b);
    cin>>a;
    b="";
    b+=a[0];
    b+=a[1];
    h2=sto(b);
    b="";
    b+=a[3];
    b+=a[4];
    m2=sto(b);

    int m=0;
    while(h1!=n(h2-1))
    {

        h1++;
        m+=60;
        if(h1>23)h1-=24;
    }

    while(h1!=h2 or m1!=m2)
    {
        m1++;
        m++;
        if(m1>=60)
        {
            m1-=60;
            h1++;
        }
        h1%=24;

    }
    c(m/60);
    cout<<":";
    c(m%60);


    return 0;
}
