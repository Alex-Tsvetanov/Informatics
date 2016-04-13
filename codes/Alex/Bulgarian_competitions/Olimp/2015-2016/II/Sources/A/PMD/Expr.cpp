#include<iostream>
using namespace std;
int main()
{
    int i=0,j;
    string s;
    cin>>s;
    while(s!="2")
    {
        cin>>s;
        i++;
    }
    for(j=1;j<i;j++)
        if(j%2==0)cout<<"1";
    else cout<<"0";
    return 0;
}
