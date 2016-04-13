#include<iostream>
using namespace std;
bool notes[100][100];
int main()
{
    int l,h,n,maxx,maxy,maxx1,maxy1;
    cin>>l>>h>>n;
    for(int i=0;i<n;i++)
    {
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        for(int y=0;y<d;y++)
        {
            for(int x=0;x<c;x++)
            {
                notes[a+x][b+y]=true;
            }
        }
    }
    int maxlice=-1;
    for(int y=0;y<h;y++)
    {
        for(int x=0;x<l;x++)
        {
            for(int y1=y;y1<h;y1++)
            {
                for(int x1=x;x1<l;x1++)
                {
                    bool IS=true;
                    int lice=(x1-x+1)*(y1-y+1);
                    for(int yt=y;yt<=y1&&IS;yt++)
                    {
                        for(int xt=x;xt<=x1&&IS;xt++)
                        {
                            if(notes[xt][yt]==1)
                            {
                                IS=false;
                            }
                        }
                    }
                    if(IS&&lice>maxlice)
                    {
                        maxx=x;
                        maxy=y;
                        maxx1=x1;
                        maxy1=y1;
                        maxlice=lice;
                    }
                }
            }
        }
    }
    cout<<maxlice<<"\n";
    return 0;
}
