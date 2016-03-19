#include<iostream>
#include<queue>
#include<stdio.h>
#include<stack>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
bool visited[1000001];
int z[1000001][2],workers[1000001];
int n,m,p,i,key=0,otg=0,j;
void null()
{
    for(j=0;j<n;j++)
        {
            visited[j]=0;
            workers[j]=0;
        }
}
int main()
{
    scanf("%d %d %d",&n,&m,&p);
    for(i=0;i<m;i++)
        scanf("%d %d",&z[i][0],&z[i][1]);
    do
    {
        key=1;
        for(i=0;i<m-1;i++)
        {
            if(z[i][0]>z[i+1][0])
            {
                swap(z[i][0],z[i+1][0]);
                swap(z[i][1],z[i+1][1]);
                //i=0;
                key=0;
            }
            else if(z[i][0]==z[i+1][0])
            {
                if(z[i][1]>z[i+1][1]) 
                {
                    swap(z[i][1],z[i+1][1]);
                    key=0;
                }
            }
        }
    }
    while(!key);
    for(i=0;i<m;i++)
    {
        key=0;
        for(j=z[i][0];j<=z[i][1];j++)
        {
            if(j%7!=0 && j%7!=6)
            {
                if(workers[j]<p/2)
                {
                    workers[j]++;
                    key=1;
                    if(j>n) key=0;
                    break;
                } 
            } 
        }
        if(key==0) {otg=1;break;}
    }
    null();
    if(otg==1)
    {
        for(i=0;i<m;i++)
        {
            key=0;
            for(j=z[i][0];j<=z[i][1];j++)
            {
                if(workers[j]<p/2)
                {
                    workers[j]++;
                    key=1;
                    if(j>n) key=0;
                    break;
                } 
            }
        if(key==0) {otg=2;break;}
        }
    }
    if(otg==0) cout<<"OK";
    else if(otg==1) cout<<"MIXED";
    else cout<<"IMPOSSIBLE";
    cout<<endl;
    
    /*printf("\n");
    for(i=0;i<m;i++)
       printf("%d %d\n",z[i][0],z[i][1]);//printf("%d ",visited[i]); 
    */
    
    return 0;
}
/*
100 3 2
4 5
5 6
5 7

100 5 4
5 5
5 7
7 8
8 9
8 9
MIXED


*/