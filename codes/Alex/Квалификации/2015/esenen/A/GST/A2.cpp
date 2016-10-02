#include<iostream>
#include<vector>
using namespace std;

int N,M,I,J,W,A[10000][10000],path[10000],mini=0,curr=65001,br=0;

void g(int x)
{
    if(x==N-1)
    {
        if(mini!=0)
        {
            if(mini<curr)mini=curr;
            }else{
            mini=curr;
            }
    }else{
        bool flag;

    for(int i=0;i<N;i++)
    {
        flag=true;
        for(int y=0;y<br;y++)if(path[y]==i)flag=false;

        if(A[x][i]!=0 and flag==true)
        {
            int lastcur=curr;
           if(curr>A[x][i])curr=A[x][i];
            path[br]=x;
            br++;
            g(i);
            br--;
            path[br]=0;
            curr=lastcur;
        }
    }


    }
}
int main()
{

    cin>>N>>M;
    for(int i=0;i<M;i++)
    {
        cin>>I>>J>>W;
        A[I-1][J-1]=W;
        A[J-1][I-1]=W;
    }
   // cout<<"0";
    g(0);
    cout<<mini<<endl;
    return 0;
}
/*
5 6
1 2 1
1 3 3
1 4 9
2 5 10
3 5 5
4 5 2

*/
