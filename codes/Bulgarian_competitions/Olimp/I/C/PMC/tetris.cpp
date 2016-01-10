#include <iostream>
using namespace std;
int main(){
    
    int n, m, i, j, br=0, score=0;
    char pole[100][100];
    cin >> n; cin >> m;
    for (i=0;i<n;i++)
    {
        for (j=0;j<m;j++)
        {
            cin >> pole[i][j];
        }
    }
    for (br;br<n-1;br++)
    {
        for (i=1;i<n;i++)
        {
            for (j=0;j<m;j++)
            {
                if(pole[i][j]=='.')
                {
                    pole[i][j]=pole[i-1][j];
                    pole[i-1][j]='.';
                }
            }
        }
    }
    for (i=0;i<n;i++)
    {
        for (j=0;j<m;j++)
        {
            if (pole[i][j]=='*') br=br+1;
        }
        if (br==m) score=score+1;
        br=0;
    }
    cout << score;
    return 0;
}