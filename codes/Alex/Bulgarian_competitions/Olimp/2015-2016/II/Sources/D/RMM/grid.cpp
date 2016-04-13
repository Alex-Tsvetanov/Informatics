# include <iostream>
using namespace std;
long long n,m,a[200][200],b[200][200],c[200][200],br=0;
int main()
{

cin>>n>>m;
int i,j;
for(i=0;i<=n+1;i++)
for(j=0;j<=m+1;j++)
a[i][j]=1;

{
    a[0][i]=1;
    a[i][0]=1;
}
for(i=1;i<=n;i++)
    for(j=1;j<=m;j++)
{
    cin>>a[i][j];

}
for(i=1;i<=n;i++)
    for(j=1;j<=m;j++)
{
    if(a[i][j]==0)
    {
        if(a[i-1][j]==0&&b[i-1][j]!=i&&c[i-1][j]!=j)
        {
            b[i][j]=i-1;
            c[i][j]=j;
        }
else
{
    if(a[i][j-1]==0&&b[i][j-1]!=i&&c[i][j-1]!=j)
        {
            b[i][j]=i;
            c[i][j]=j-1;
        }
        else
        {
            if(a[i+1][j]==0&&b[i+1][j]!=i&&c[i+1][j]!=j)
            {
                b[i][j]=i+1;
                c[i][j]=j;
            }
        else
        {
            if(a[i][j+1]==0&&b[i][j+1]!=i&&c[i][j+1]!=j)
        {
            b[i][j]=i;
            c[i][j]=j+1;
        }
        else
            br++;
        }
        }


}

    }
}
/*for(i=1;i<=n;i++)
    for(j=1;j<=m;j++)
    cout<<b[i][j]<<" "<<c[i][j]<<endl;*/
cout<<br<<endl;
return 0;
}
