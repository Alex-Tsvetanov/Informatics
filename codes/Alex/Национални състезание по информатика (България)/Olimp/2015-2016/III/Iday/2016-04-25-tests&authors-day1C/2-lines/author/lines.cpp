#include <iostream>
using namespace std;

const int M = 1000000007;

int dp[1024][1024];

int main()
{ int n0,i0,j0;
  cin >> n0 >> i0 >> j0;
  
  dp[2][1]=1;
  for(int n=3; n<=n0; n++)
  { for(int j=1; j<=n/2; j++)
    { int d=1;
      for(int k=1; k<j; k++)
        d = (d + dp[n-k][j-k])%M;
      for(int k=j+1; k<n; k++)
        d = (d + dp[k][j])%M;
      dp[n][j] = d;
      dp[n][n-j] = d;   
    }
  }
  cout << dp[n0][j0-i0] << endl;  
    
  return 0;  
}