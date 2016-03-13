#include <cstdio>
using namespace std;


int a[1001][1001];
int prov(int st1,int st2,int m,int n)
{
    int sum=0;
    for(int i=st1; i<st1+m; i++)
    {
        for(int j=st2; j<st2+n; j++)
        {
            sum+=a[i][j];
        }
    }
    return sum;
}
int main()
{
    int M,N,m,n;
    scanf("%d%d%d%d",&M,&N,&m,&n);

    for(int i=0; i<M; i++)
    {
        for(int j=0; j<N; j++)
        {
            scanf("%d",&a[i][j]);
            //cin>>a[i][j];
        }
    }
    int maxi=0;

    for(int i=0; i<M-m+1; i++)
    {
        for(int j=0; j<N-n+1; j++)
        {
            //cout<<"HERE";
            if(prov(i,j,m,n)>maxi)maxi=prov(i,j,m,n);
        }
    }
    printf("%d\n",maxi);


    return 0;
}
