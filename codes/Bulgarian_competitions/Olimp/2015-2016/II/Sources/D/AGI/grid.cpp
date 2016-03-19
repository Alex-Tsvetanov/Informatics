#include<iostream>
using namespace std;
int main()
{
    int n, m, a[200][200], i, j, br=0;
    cin>>n>>m;
    for(i=0; i<m; i++)
    {
        for(j=0; j<n; j++)cin>>a[i][j];
    }
    for(i=0; i<m; i++)
    {
        for(j=0; j<n; j++)
        {
            if(a[i][j]!=0)br++;
        }
    }
    if((n*m)%2==0)cout<<br<<endl;
    else cout<<br+1<<endl;
return 0;
}
