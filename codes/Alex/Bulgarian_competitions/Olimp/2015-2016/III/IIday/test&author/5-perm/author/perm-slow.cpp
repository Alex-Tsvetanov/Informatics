#include <iostream>
#include <algorithm>
using namespace std;

int a[32];

int n;
long long k;

bool ok()
{ for(int i=1; i<=n; i++)
    if(a[a[i]] != i) return false;
  return true;
}

int main()
{ cin >> n >> k; 
  
  for(int i=1; i<=n; i++) a[i]=i;
  long long m=1;
  while(m<k)
  { next_permutation(a+1,a+n+1);    
    if(ok()) m++;
  }
      
  for(int i=1; i<n; i++)
    cout << a[i] << " ";
  cout << a[n] << endl;  
  
  return 0;
}
