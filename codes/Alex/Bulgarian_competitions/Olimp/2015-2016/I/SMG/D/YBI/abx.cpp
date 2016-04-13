#include<iostream>
#include<string>
using namespace std;
long long a=0,b=0,x=0;
string eq;
void Solve()
{
    if(eq[0]=='X')
    {
        eq.erase(0,2);
        while(eq[0]!='=')
        {
            a=10*a+eq[0]-'0';
            eq.erase(0,1);
        }
        eq.erase(0,1);
        while(eq.size()!=0)
        {
            b=10*b+eq[0]-'0';
            eq.erase(0,1);
        }
    }
    else
    {
        while(eq[0]!='+')
        {
            a=10*a+eq[0]-'0';
            eq.erase(0,1);
        }
        eq.erase(0,3);
        while(eq.size()!=0)
        {
            b=10*b+eq[0]-'0';
            eq.erase(0,1);
        }
    }
}
int main()
{

    cin>>eq;
    Solve();
    cout<<b-a<<"\n";
    return 0;
}
