#include <iostream>
using namespace std;
int sumr[1001][1001], sumc[1001][1001];
int table[1001][1001];//red, kolona
int main()
{
    int tr = 0, tc = 0, fr = 0, fc = 0;
    cin >> tr >> tc >> fr >> fc;
    for(int i = 0; i < tr; i ++) for(int j = 0; j < tc; j ++) cin >> table[i][j];
    for(int i = 0; i < tr; i ++)
    {
        sumr[i][0] = table[i][0];
        for(int j = 1; j < tc; j ++) sumr[i][j] = sumr[i][j-1]+table[i][j];
        //cout << sumr[i][tc-1] << endl;
    }
    for(int i = 0; i < tc; i ++)
    {
        sumc[0][i] = table[0][i];
        for(int j = 1; j < tr; j ++) sumc[j][i] = sumc[j-1][i]+table[j][i];
    }
    int ans = 0, lastl = 0, lastu = 0;
    for(int i = 0; i < fr; i ++)
    {
        for(int j = 0; j < fc; j ++)
        {
            ans += table[i][j];
        }
    }
    lastl = ans;
    lastu = ans;
    //cout << lastl << endl;
    for(int i = 0; i < tr; i ++)
    {
        if(i != 0 && i+fr <= tr)
        {
            lastu = lastu-sumr[i-1][fc-1]+sumr[i+fr-1][fc-1];
            //cout << lastu << endl;
            lastl = lastu;
            ans = max(ans, lastu);
        }
        for(int j = 1; j < tc; j ++)
        {
            if(i+fr<=tr&&j+fc<=tc)
            {
                lastl = lastl-sumc[i+fr-1][j-1]+(i>0?sumc[i-1][j-1]:0) + sumc[i+fr-1][j+fc-1]-(i>0?sumc[i-1][j+fc-1]:0);
                //cout << i << " " << j << " " << lastl << " " << (-sumc[i+fr-1][j-1]+(i>0?sumc[i-1][j-1]:0)) << " " << sumc[i+fr-1][j+fc-1]-(i>0?sumc[i-1][j+fc-1]:0) << endl;
                ans = max(ans, lastl);
            }
        }
    }
    cout << ans << endl;
}
