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
struct den
{
    int x, y;
};
int main()
{
    long long n,m,p;

    cin>>n>>m>>p;
    vector<den>s;
    int v=0;
    for(int i=0;i<m;i++)
    {
        den f;
        cin>>f.x;
        cin>>f.y;
        if((f.x+1)%7==0||f.x%7==0)v=1;
         if((f.y+1)%7==0||f.y%7==0)v=1;

        s.push_back(f);
    }
    if(v==0)cout<<"OK"<<endl;
      else cout<<"MIXED"<<endl;




return 0;
}
