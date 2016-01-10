#include <iostream>
#include <cstring>
using namespace std;
int convert(char a[])
{
    int i,s;
    s=strlen(a);
    if(s=3)
        i=a[2]*100+a[1]*10+a[0];
    if(s=2)
        i=a[1]*10+a[0];
    if(s=1)
        i=a[0];
    return i;
}


int main ( )
{
    int br,achis,bchis,rez;
    char b[5],uravnenie[19],x[5],a[5];
    char c;
    cin >> uravnenie;
    for (br=0;uravnenie[br]!='+';++br){
        a[br]=uravnenie[br];
    }++br;
    for (;uravnenie[br]!='=';++br){
        x[br]=uravnenie[br];
    }++br;
    for (;uravnenie[br]!='\0';++br){
        b[br]=uravnenie[br];
    }
    if(a[0]=='x')
        strcpy(a,x);
    achis=convert(a);
    bchis=convert(b);
    rez=bchis-achis;
    cout << rez;
    return 0;
}
