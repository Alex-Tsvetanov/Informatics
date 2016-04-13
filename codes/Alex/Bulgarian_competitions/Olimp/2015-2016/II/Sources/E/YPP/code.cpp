#include<iostream>
#include<string>
using namespace std;

int main()
{
  string s;
  getline(cin,s);
  int n=s.size();
  n=n-1;
  int x=0,y=0,m=0;
  for(int i=0;i<n;i++)
  {
    if(s[i]!=s[i+1])
    x=0;
    else
    while(s[i]==s[i+1])
    {
      x++;
      if(x<10 && x>1)
       y=2;
      if(x>10)
       y=3;
      i++;
    }
    m=y;
    x=0;
  }
  cout << m << endl;







  return 0;
}
