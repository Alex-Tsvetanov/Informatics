#include<iostream>
using namespace std;

int p, n, s;

long long int b[21][31];

int dp()
{
  for(int j=0;j<s;j++) b[1][j]= (j<p?1:0);  
  for(int i=1;i<=n;i++) b[i][0]=1;
  
  for(int i=2;i<=n;i++)
  for(int j=1;j<s;j++)
  {
    long long int t=0;
    for(int k=0;k<p;k++) 
     if(j-k>=0) t += b[i-1][j-k];
    b[i][j]=t;
  } 
    
 
  long long r=0;
  for(int j=0;j<s;j++) r += b[n][j];
  cout << r << endl;

}


int main()
{
  cin >> p >> n >> s;
  dp();
}
