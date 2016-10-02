#include<iostream>
using namespace std;
int main()
{
    char a[4],b[4],kol,kol2;
    cin>>a>>b;
    kol=a[0];
    int v,q[2],f,redi,m,n,redi2;
    //pole
    for(int re=1; a[re]!='\0'; re++)
    {
        v=re;
        q[v]=a[re]-48;
    }
    m=a[1]-48;
    n=a[2]-48;
    if(v==1)
    {
        redi=m;
    }
    if(v==2)
    {
        redi=m*10+n;
    }
    //kon
    kol2=b[0];
    for(int re=1; b[re]!='\0'; re++)
    {
        v=re;
        q[v]=b[re]-48;
    }
    m=b[1]-48;
    n=b[2]-48;
    if(v==1)
    {
        redi2=m;
    }
    if(v==2)
    {
        redi2=m*10+n;
    }

    //iskarwane
    cout<<"  ";
    if(redi>=10){
        cout<<" ";
    }
    int j=kol-96+'a',ki,ko,konx,kony,polx,poly;
    ki=0;
    konx=kol2-97;
    kony=redi2-1;
    for(char u='a'; u<j; u++)
    {
        cout<<u;
        ki++;
    }
    cout<<endl;
    for(int de=1; de<=redi; de++)
    {
        if(de<=9 and redi>=10){
            cout<<" ";
        }
        cout<<de<<" ";
        for(ko=0; ko<kol-96; ko++)
        {
            polx=ko;
            poly=de-1;
            if((poly==kony-2 and polx==konx-1) or (poly==kony-2 and polx==konx+1) or (poly==kony-1 and polx==konx-2) or (poly==kony-1 and polx==konx+2) or (poly==kony+2 and polx==konx-1) or (poly==kony+2 and polx==konx+1) or (poly==kony+1 and polx==konx-2) or (poly==kony+1 and polx==konx+2))
            {
                cout<<"X";
            }
            else
            {
                if(poly==kony and polx==konx)
                {
                    cout<<"K";
                }
                else
                {
                    cout<<"O";
                }
            }
        }
        cout<<endl;
    }
    return 0;
}
