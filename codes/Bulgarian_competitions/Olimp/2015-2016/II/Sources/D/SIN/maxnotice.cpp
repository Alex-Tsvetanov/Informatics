#include<iostream>
using namespace std;
int duska[100][100],x,y,n,masifbr[100],br,streak,lstreak,ans,be;

int fillzone (int a1,int b1,int c1,int d1)
{
    for (int i=a1;i<a1+c1;i++)
        for (int j=b1;j<b1+d1;j++)
            duska[i][j]=1;
}

int main ()
{
    cin>>y>>x;
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        int a,b,c,d;
        cin>>b>>a>>d>>c;
        fillzone (a,b,c,d);
    }
    for (int i=x;i>=1;i--)
    {
        for (int j=0;j<100;j++) masifbr[j]=0;

        for (int j=0 , j2=i ; j2<x ; j++ , j2++)
        {
            for (int k=0;k<y;k++)
            {
                br=0;
                for (int l=j;l<=j+j2;l++) br+=duska[l][k];
                if (br==0) masifbr[k]=1;

            }
            streak=0; lstreak=0;
            for (int k=0;k<y;k++)
            {
                if (masifbr[k]==1) streak++;
                if (masifbr[k]==0 || k==y-1)
                {
                    if (streak>lstreak) lstreak=streak;
                    streak=0;
                }
            }
            if (ans<lstreak*(i+1))
            {
                ans=lstreak*(i+1);
                if (lstreak==y) {be=1; break;}
            }
            if (be==1) break;
        }
        if (be==1) break;
    }
    cout<<ans<<endl;
    return 0;
}
/*
12 8
2
2 0 3 3
6 1 5 4
*/
