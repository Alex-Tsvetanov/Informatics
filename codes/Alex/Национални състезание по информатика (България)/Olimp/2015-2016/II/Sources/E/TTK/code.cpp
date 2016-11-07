#include<iostream>
#include<string.h>
using namespace std;
char a[1000001];
int main()
{
    long long n,i,br=1,br2=0;
    char c;
    cin>>a;
    n=strlen(a)-1;
    c=a[0];
    for(i=1;i<=n;i++)
    {
        if(c==a[i])br++;
        else if(br>999999){br2=br2+8;br=1;}else if(br>99999){br2=7+br2;br=1;}else if(br>9999){br2=br2+6;br=1;}else if(br>999){br2=br2+5;br=1;}else if(br>99){br2=br2+4;br=1;}else if(br>9){br2=br2+3;br=1;}else if(br>1){br2=br2+2;br=1;}else if(br==1){br2++;br=1;}
        c=a[i];
    }
    cout<<n-br2<<endl;
    return 0;
}
