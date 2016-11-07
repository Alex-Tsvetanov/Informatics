#include <iostream>
using namespace std;
int main()
{
int m,n,a[200][200],a1[200][200],ch=0,flag=1,br=0,br1=0,i,y,flag1=0;
cin>>m>>n;
for(int i=0;i<m;i++)
    {
        for(int y=0;y<n;y++)
        {
        cin>>a[i][y];
        a1[i][y]=0;
        if(a[i][y]==0)br++;
        }
    }
    a1[0][0]=1;
    i=0;
    y=0;
    while(br!=0)
    {
        ch++;
        flag--;
        flag1--;
    while(flag==0)
    {
        if(a[i+1][y]==0)
        {
            a1[i+1][y]==ch;
            br--;
            br1++;
            i++;
        }
                if(a[i][y+1]==0)
        {
            a1[i][y+1]==ch;
            br--;
            br1++;
            y++;

        }
        if(i>0)

                if(a[i-1][y]==0)
        {
            a1[i-1][y]==ch;
            br--;
            br1++;
            i--;
        }
                if(a[i][y-1]==0)
        {
            a1[i][y-1]==ch;
            br--;
            br1++;
            y--;
        }
        if(br1==0)flag=1;
    }
        if(br>0)
        {
        i=0;
        y=0;
        for(i;i<m&&flag1==0;i++)
        {
            for(y;y<n&&flag1==0;y++)
            {
                if(a[i][y]==0)flag1=1;
            }
        }
        }
    }
    cout<<ch<<endl;
return 0;
}
