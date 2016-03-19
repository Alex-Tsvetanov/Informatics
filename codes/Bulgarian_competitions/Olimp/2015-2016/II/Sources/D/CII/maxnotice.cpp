#include<iostream>
using namespace std;
long long table[104][104],table1[104][104],maxs,l,h,np,a,b,c,d,l1=-1,h1=1;
int main()
{
    cin>>l>>h;
    cin>>np;
    for(int i=1;i<=h;i++)
        table1[i][0]=table[i][0]=table1[i][l+1]=table[i][l+1]=1;
    for(int i=1;i<=l;i++)
        table1[0][i]=table[0][i]=table1[h+1][i]=table[h+1][i]=1;

    for(int i=0; i<np; i++)
    {
        cin>>a>>b>>c>>d;
        for(int x=b+1; x<=b+d; x++)
            for(int y=a+1; y<=a+c; y++)
                table1[x][y]=table[x][y]=1;
    }
    for(int i=1; i<=h; i++)
    {
        for(int j=1; j<=l; j++)
        {
            table1[i][j]=table1[i-1][j]+table1[i][j-1]-table1[i-1][j-1];
        }
    }
    for(int i=1; i<=h; i++)
        for(int j=1; j<=l; j++)
        {
            if(table[i][j]==0)
            {
                int i1=i,j1=j;
                while(table[i][j1]!=1)
                    j1++;
                j1--;
                while(table1[i1][j1]-table1[i-1][j1]-table1[i1][j-1]+table1[i-1][j-1]==0)
                    i1++;
                i1--;
                if((i1-i-1)*(j1-j-1)>maxs)
                    maxs=(i1-i-1)*(j1-j-1);
                i1=i;
                j1=j;
                while(table[i1][j]!=1){
                    i1++;
                //cout<<"lol";
                }
                i1--;
                while(table1[i1][j1]-table1[i-1][j1]-table1[i1][j-1]+table1[i-1][j-1]==0)
                    j1++;
                j1--;
                if((i1-i-1)*(j1-j-1)>maxs)
                    maxs=(i1-i-1)*(j1-j-1);
            }
        }
    cout<<maxs<<endl;
    return 0;
}
/**
12 8
2
2 0 3 3
6 1 5 4
*/
