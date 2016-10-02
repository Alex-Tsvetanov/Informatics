#include<iostream>
#include<cmath>
using namespace std;
bool table[1001][1001]={false};
bool table2[1001][1001]={false};
int n,m,t,temp1,temp2;
void cpy()
{
    for(int i = 0;i < n;i++)
        for(int j = 0;j < m;j++)
            table2[i][j] = table[i][j];
}
int main()
{
    cin>>n>>m>>t;
    cin>>temp1>>temp2;
    table[n-temp1][temp2-1] = true;
    cin>>temp1>>temp2;
    table[n-temp1][temp2-1] = true;
    cpy();
    for(int i = 0;i < t;i++)
    {
        for(int q = 0;q < n;q++)
        {
            for(int j = 0;j < m;j++)
            {
                if(table2[q][j])
                {
                    table[(int)abs(q-1)][j] = true;
                    table[q][(int)abs(j-1)] = true;
                    table[(int)(n-abs(n-q-2)-1)][j] = true;
                    table[q][(int)(m-abs(m-j-2)-1)] = true;
                }
            }
        }
        cpy();
    }
    temp1 = 0;
    for(int i = 0;i < n;i++)
        for(int j = 0;j < m;j++)
            if(!table2[i][j])
                temp1++;
    cout<<temp1<<endl;
    return 0;
}
