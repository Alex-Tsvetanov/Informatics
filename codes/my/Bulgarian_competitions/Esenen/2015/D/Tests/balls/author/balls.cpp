#include<iostream>
#include<climits>
using namespace std;
long long int a;
int main()
{ int n, k;
  long long int max=LLONG_MIN;
  long long int min=LLONG_MAX;
  cin>>n>>k;

  for(int i=1;i<=n;i++)
  {
  cin>>a;
  if(max<a) max=a;
  if(min>a) min=a;
  }

  cout<<max-min<<endl;
 
}
