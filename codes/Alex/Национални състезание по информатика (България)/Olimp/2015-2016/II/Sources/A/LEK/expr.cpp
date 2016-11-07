#include<iostream>
#include<stdio.h>
using namespace std;
char a[1024];
char b[32];
int i;
bool solve(int start)
{
    bool Sol;
    for (i=start;a[i]!=')' && a[i];i++)
    {
        if (a[i]=='(') Sol=!(Sol&solve(i+1));
        else if (i==start) Sol=b[a[i]-97]-'0';
        else Sol=!(Sol&(b[a[i]-97]-'0'));
    }
    return Sol;
}
void inp()
{
    scanf("%s", a);
    do
    {
    scanf("%s", b);
    if (b[0]=='2') break;
    i=0;
    printf("%d",solve(0));
    }while(true);
    printf("\n");
}
//!(a&b)
int main()
{
    inp();
    return 0;
}