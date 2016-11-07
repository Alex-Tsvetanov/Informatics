#include<iostream>
using namespace std;

const int MAXVAL=(int)1e9;
const int N=10002;
bool p[N][N];
int c[N];

int partition(string s)
{
  int n = s.length();
  for (int i = 0; i < n; i++) p[i][i] = true;

  for (int i = 0; i < n-1; i++)
    if (s[i] == s[i+1]) p[i][i+1] = true;

  for (int len = 3; len <= n; len++)
   for (int i = 0; i < n-len+1; i++)
     {
        int j = i+len-1;
        if ((s[i] == s[j]) && p[i+1][j-1]) p[i][j] = true;
     }

  for(int i=0; i<n; i++)
    {
        int temp = MAXVAL;
        if(p[0][i]) c[i] = 0;
        else
        {
         for(int j=0; j<i; j++)
          if(p[j+1][i])
            if(temp > c[j] + 1) temp = c[j] + 1;
         c[i] = temp;
        }
    }

  return c[n-1];
}

int main()
{
  string s; cin >> s;
  cout << partition(s);
}


