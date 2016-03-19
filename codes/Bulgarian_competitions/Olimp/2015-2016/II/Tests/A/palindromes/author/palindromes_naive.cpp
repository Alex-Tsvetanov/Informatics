#include<iostream>
using namespace std;

string s;
int n;

bool check(int i1, int i2)
{
  //cout << i1 << " " << i2 << endl;
  int k=0;
  while(i1+k<i2-k)
  {
   if(s[i1+k]!=s[i2-k]) {return false;}
   k++;
  }
  return true;
}

int maxcheck(int i1)
{
  int m=0;
  int i3=i1+1;
  for(int i2=i1;i2<=n-1;i2++)
  if(check(i1,i2))
   if(m < i2-i1+1) {m = i2-i1+1; i3=i2+1;}
  return i3;
}

int main()
{
  cin >> s;
  n = s.length();
  int c=0;

  int i=0;
  while(i<n)
  {
    i=maxcheck(i);
    c++;
  }
  cout << c-1 << endl;
}


