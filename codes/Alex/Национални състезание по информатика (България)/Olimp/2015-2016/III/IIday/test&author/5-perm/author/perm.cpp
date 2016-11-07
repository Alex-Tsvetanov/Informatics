/**
  Задача: Пермутации
  Група C, НОИ-3, 2016 г.
  Автор: Стоян Капралов
*/

#include <iostream>
#include <vector>
using namespace std;

int a[32];
long long c[32];
vector<pair<int,int>> transp;

void solve(int n, long long k)
{ if(n<2) return;
  if(k<=c[n-1])
  { // Пермутацията започва с a[1]
    for(int i=1; i<n; i++) a[i] = a[i+1];
    solve(n-1,k);
    return;
  }
  // Транспозиция на a[1] и a[p]
  k = k-c[n-1];
  int p=(k-1)/c[n-2];
  k = k - p*c[n-2];
  p = p+2;
  transp.push_back(make_pair(a[1],a[p]));
  for(int i=p; i<n; i++)  a[i] = a[i+1];
  for(int i=1; i<n-1; i++) a[i] = a[i+1];
  solve(n-2,k);  
}

int main()
{ int n;
  long long k;
  cin >> n >> k; 
  
  c[0]=1; c[1]=1;
  for(int i=2; i<n; i++)
    c[i] = c[i-1]+(i-1)*c[i-2];
    
  for(int i=1; i<=n; i++) a[i]=i;
    
  solve(n,k);
  
  for(int i=1; i<=n; i++) a[i]=i;  
  for(auto t: transp)
    swap(a[t.first],a[t.second]);
  
  for(int i=1; i<n; i++)
    cout << a[i] << " ";
  cout << a[n] << endl;  
  
  return 0;
}
