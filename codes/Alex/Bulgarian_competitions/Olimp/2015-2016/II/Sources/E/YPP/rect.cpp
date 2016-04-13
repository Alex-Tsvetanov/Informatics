#include<iostream>
using namespace std;

int main()
{
  int n,br=0;
  cin >> n;
  if((n-4)%3==0)
  br++;
  if((n-7)%5==0)
  br++;
  if((n-10)%7==0)
  br++;
  if(br>0)
  cout << br << endl;
  else
  cout << 0 << endl;





  return 0;
}
