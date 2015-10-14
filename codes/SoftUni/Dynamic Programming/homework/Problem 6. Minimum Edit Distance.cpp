#include<iostream>
using namespace std;
 
int insert_cost, remove_cost, replace_cost;

int min(int x, int y, int z) 
{
   return min(min(x, y), z);
}
 
 
int editDistDP(string str1, string str2, int m, int n)
{
    int dp[m+1][n+1];
 
    for (int i=0; i<=m; i++)
    {
        for (int j=0; j<=n; j++)
        {
            if (i==0)
                dp[i][j] = j;
            else if (j==0)
                dp[i][j] = i;
 
            else if (str1[i-1] == str2[j-1])
                dp[i][j] = dp[i-1][j-1];
            else
            {
                int Insert = dp[i][j-1]+insert_cost;
                int Remove = dp[i-1][j]+remove_cost;
                int Replace = dp[i-1][j-1]+replace_cost;
                dp[i][j] = min(Insert, Remove, Replace);
                if (dp[i][j] == Insert)
                {
                   
                }
            }
        }
    }
 
    return dp[m][n];
}

int main()
{
    cin >> insert_cost >> remove_cost >> replace_cost;
    string str1;
    string str2;
    cin >> str1 >> str2;
 
    cout << editDist( str1 , str2 , str1.length(), str2.length());
 
    return 0;
}
