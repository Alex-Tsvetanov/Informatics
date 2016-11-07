#include<iostream>

using namespace std;

bool a[105][105];
int dp[105][105];


int main()
{
    int n,m;
    int number_notice = 0,l,h,x,y;

    int max_size = 0;
    int current_min = 105;
    int current_lenght = 0;

    cin >> m >> n;
    cin >> number_notice;
    for(int notice = 0;notice<number_notice;notice++)
    {
        cin >> x >> y >> l >> h;

        for(int i = y;i<y+h;i++)
            for(int j = x;j<x+l;j++)
                a[i][j] = true;
    }

    for(int j = 0;j<m;j++)
    {
        current_lenght = 0;
        for(int i = n-1;i>=0;i--)
        {
            if(a[i][j]==false) current_lenght++;
            else current_lenght = 0;

            dp[i][j] = current_lenght;
        }
    }

    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<m;j++)
        {
            current_min = 105;
            for(int f = j;f<m;f++)
            {
                if(dp[i][f]==0) break;

                if(dp[i][f]<current_min) current_min = dp[i][f];
                if((f-j+1)*current_min>max_size) max_size = (f-j+1)*current_min;
            }

        }
    }

    cout << max_size << endl;

    return 0;

}

/*
    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<m;j++)
        {
            current_min = 105;

            if(a[i][j]==false)
            {
                for(int colum = j;colum<m;colum++)
                {
                    if(a[i][colum]==true) break;

                    current_lenght = 0;
                    for(int row = i;row<n;row++)
                        if(a[row][colum]==false) current_lenght++;
                        else break;

                    if(current_lenght<current_min) current_min = current_lenght;

                    if((colum-j+1)*)
                }
            }
        }
    }
*/
/*
12 8
2
2 0 3 3
6 1 5 4
*/
