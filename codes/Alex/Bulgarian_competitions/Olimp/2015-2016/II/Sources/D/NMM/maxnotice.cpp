#include<iostream>
using namespace std;

int tabl[108][108];
int l,h;

struct note
{
    int x;
    int y;
    int l;
    int h;
};

note s[20];


int fs(int x, int y)
{
    int s1,s2;

    int ld=y, hd=x;

    while(ld+1<l && tabl[x][ld+1]==0)
        ld++;

    while(hd+1<h && tabl[hd+1][y]==0)
        hd++;

    //cout<<" "<<x<<" "<<y<<endl;
    //cout<<ld<<" "<<hd<<endl;
    s1= (ld-y+1) * (hd-x+1);
    s2=s1;
    //cout<<s1<<endl;
    for(int i=x;i<=hd;i++)
    {
        for(int j=y;j<=ld;j++)
        {
            if(tabl[i][j]==1)
            {
                s1=s1-(ld-y+1) * (hd-i+1);
                s2=s2-(ld-j+1) * (hd-x+1);
                j=ld+1;
                i=hd+1;
                //cout<<"ii"<<endl;
            }
        }
    }
    //cout<<s1<<" /"<<s2<<endl;
    return max(s1,s2);
    // 4 5
    // 5 7

}

int main()
{
    cin>>l>>h;

    int n;
    cin>>n;

    for(int p=0;p<n;p++)
    {
        cin>>s[p].y>>s[p].x>>s[p].l>>s[p].h;

        for(int i= (s[p].x) ;i< (s[p].x+s[p].h) ;i++)
        {
            for(int j= (s[p].y) ;j< (s[p].y+s[p].l) ;j++)
            {
                tabl[i][j]=1;
            }
        }
    }

    int maxr=0;

    for(int i=0;i<h;i++)
    {
        for(int j=0;j<l;j++)
        {
            int r=fs(i,j);
            if(maxr<r)
            {
                maxr=r;
                //cout<<i<<" "<<j<<endl;
            }
        }
    }
    cout<<maxr<<endl;
    return 0;
}
/*
12 8
2
2 0 3 3
6 1 5 4
*/
