#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <bitset>

using namespace std;

string inS;

bool isItP(string tempI)
{
    int flag=0,j=tempI.length()-1;
    for(int i=0; i<tempI.length(); i++)
    {
        if(tempI[i]==tempI[j])
        {
            j--;
            continue;
        }
        else
        {
            flag=1;
            break;
        }
    }
    if(flag) return false;
    else return true;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>inS;
    if(isItP(inS)==true) cout<<0<<endl;
    else cout<<1<<endl;


    return 0;
}

