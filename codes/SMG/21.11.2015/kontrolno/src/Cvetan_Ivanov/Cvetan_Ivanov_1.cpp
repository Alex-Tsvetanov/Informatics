#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<time.h>
#include<stdio.h>
using namespace std;
int chas1,chas2,minuti1,minuti2,rezchas,rezminuti,om1,om2,omrez;
char a[5];
int main()
{
    cin>>a;
    chas1=(a[0]-'0')*10+(a[1]-'0');
    minuti1=(a[3]-'0')*10+(a[4]-'0');
    cin>>a;
    chas2=(a[0]-'0')*10+(a[1]-'0');
    minuti2=(a[3]-'0')*10+(a[4]-'0');
    om1=chas1*60+minuti1;
    om2=chas2*60+minuti2;
    if(om2<om1)
    {
        om2+=1440;
    }
    omrez=om2-om1;
    rezchas=omrez/60;
    rezminuti=omrez%60;
    if(rezchas<10)
        cout<<"0";
    cout<<rezchas;
    cout<<":";
    if(rezminuti<10)
        cout<<"0";
    cout<<rezminuti<<endl;
        return 0;
}
