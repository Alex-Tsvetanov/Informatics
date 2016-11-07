#include <iostream>
using namespace std;

int p,n,s,cnt;

void Solve(int i,int cs)
{
 int j;

 if(i==n && cs<s)
  cnt++;

 if(i==n || cs>=s)
  return;

 for(j=0;j<p;j++)
  Solve(i+1,cs+j);
}

int main()
{

cin>>p>>n>>s;

Solve(0,0);

cout<<cnt<<endl;

return 0;
}
