# include <iostream>
using namespace std;
int main()
{
int l,h,i,j,a[101][101],b[201][201],br=0,maxs=0;
int x,y,n,m,p,v,q;

cin>>h>>l;
cin>>v;
for(i=1;i<=v;i++)
{
    cin>>y>>x>>n>>m;
    for(p=x;p<x+m;p++)
        for(q=y;q<y+n;q++)
        a[p][q]=1;
}


for(j=0;j<h;j++)
{
    for(i=l-1;i>=0;i--)
    {
       if(a[i][j]==0)
        {
            br++;
            b[i][j]=br;
        }
       else
        {
           br=0;
            b[i][j]=0;

        }
    }
    br=0;

}
/*for(i=0;i<l;i++)
{
    for(j=0;j<h;j++)
        cout<<b[i][j]<<" ";
    cout<<endl;
}*/

br=0;
p=0;

for(i=0;i<l;i++)
{
    for(j=h-1;j>=0;j--)
    {
        if(p==b[i][j])
        {br++;

                b[i][j]=br*b[i][j];
        if(b[i][j]>maxs)
        {
            maxs=b[i][j];
        }



        }
        else
        {
            p=b[i][j];
            br=1;
            if(b[i][j]>maxs)
        {
            maxs=b[i][j];
        }

        }
    }
    p=0;
    br=0;
}

cout<<maxs<<endl;
return 0;
}
