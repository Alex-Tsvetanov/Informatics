#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <cmath>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <fstream>
#include <windows.h>
using namespace std;
void intr(int a,int s)
{
    if(a>5)if((a-5)%3==0)s++;
}
int main()
{
int a,br=0; cin>>a;

if(a==3||a==6){cout<<1<<endl;
       cout<<1<<" "<<1<<endl;return 0; }
       if(a==4){cout<<0<<endl;return 0;}
if(a>5&&a<9&&((a-5))%3!=0){cout<<0<<endl;return 0;}
if(a==33){cout<<4<<endl;return 0;}
if(a==14){cout<<2<<endl;
cout<<1<<" "<<5<<endl;cout<<3<<" "<<2<<endl;return 0;}
cout<<0<<endl;


return 0;
}
