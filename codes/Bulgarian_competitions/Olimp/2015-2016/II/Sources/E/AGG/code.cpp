#include <iostream>
using namespace std;
int main()
{
    char a[10000000];
    int i=1,br=1;
    a[0]='.';
    cin.get (a[1]);
    for(;a[i]!='\0';)
    {
        if(a[i]==a[i-1]) br++;
        else {if(br>1) {cout<<br;cout<<a[i-1];}br=1;}
        if(a[i]!=a[i-1]&&a[i]!=a[i+1]) cout<<a[i];
        i++;
        cin.get (a[i]);
    }
    cout<<endl;
    return 0;
}
