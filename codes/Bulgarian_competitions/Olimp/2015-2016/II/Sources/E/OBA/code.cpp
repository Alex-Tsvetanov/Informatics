#include<iostream>
using namespace std;
char n[1000000];
long long br=0,i=0,allbr=0;
int main()
{
    cin.getline (n,1000000,'\n');
    n[-1]='0';
    for (i=0;i<=1000000;i++)
    {
        if (n[i]!=n[i-1] && n[i]!=n[i+1]) allbr++;
        else if (n[i]==n[i-1] && n[i]!=n[i+1]) allbr=allbr+2;
        if (n[i+1]=='.') break;
    }
    cout<<(i+1)-allbr<<endl;
    return 0;
}
