#include<iostream>

using namespace std;

int main()
{
    int s=0;

    int M, N, m, n;
    cin>>M>>N>>m>>n;
    int table[M][N];
    int shorterTable[M][N-n+1];
    for(int i=0;i<M;i++)
    {
        for(int j=0;j<N;j++)
        {
            shorterTable[i][j]=0;
        }
    }
    for(int i=0;i<M;i++)
    {
        int temp=0, c=0;
        for(int j=0;j<N;j++)
        {
            cin>>table[i][j];
            temp+=table[i][j];
            if(j>=n-1)
            {
                shorterTable[i][c]=temp;
                temp-=table[i][j-n+1];
                c++;
            }
        }
    }

    for(int j=0;j<N-n+1;j++)
    {
        int temp=0;
        for(int i=0;i<M;i++)
        {
            temp+=shorterTable[i][j];
            if(i>=m-1)
            {
                if(s<temp)
                {
                    s=temp;
                }
                temp-=shorterTable[i-m+1][j];
            }
        }
    }

    cout<<s<<endl;
}
