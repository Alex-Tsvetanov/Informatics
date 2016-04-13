#include<iostream>
using namespace std;

const int N=1000002;

int n;
int a[N];

int main()
{
  cin >> n;
  for(int i=0;i<n;i++) cin >> a[i];

  for(int i=0;i<n;i++)
  {
    int c=a[i];
    bool L=true;
    for(int j=i+1;j<n;j++) if(a[j]>c){L=false; break;}
    if(L){if(i<n-1) cout << c << " "; else cout << c << endl;}
   }
}
