#include<iostream>
using namespace std;
int main()
{
    int N,M,x,y,solutions=1;
    cin>>N>>M;
    char pole[N][M];
    for(int y=0; y<N; y++)
    {
        for(int x=0; x<M; x++)
        {
            cin>>pole[x][y];
        }
    }

    bool isEmpty=false;
    while(!isEmpty)
    {

        for(int y=N-1; y>=0; y--)
        {
            for(int x=0; x<M; x++)
            {

                if(pole[x][y]=='.' && pole[x][y-1]=='*')
                {
                    for(int ry = y-1; y>=0; y--)
                    {
                        pole[x][ry] = pole[x][ry+1];
                    }

                }
            }
        }
        for(int x=0; x<M; x++)
        {
            for(int y=0; y<N; y++)
            {
                if(pole[x][y] == '*')
                {
                    isEmpty=true;
                }
            }
        }
    }
    for(int y=0; y<N; y++)
    {
        bool isLineClear = true;
        for(int x=0; x<M; x++)
        {
            if(pole[x][y] == '*')
            {
                isLineClear=false;
            }
        }
        if(isLineClear){
           solutions = solutions*(solutions+1)+1;
        }
    }
    cout<<solutions<<endl;
    return 0;
}

