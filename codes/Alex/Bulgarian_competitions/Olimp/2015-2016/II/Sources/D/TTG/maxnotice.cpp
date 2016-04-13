#include<iostream>
using namespace std;
int l,h,n;
bool a[100][100];
void Init()
{

    int c=0,b=0;
    int t=0,v=0;
    cin>>l>>h;
    cin>>n;
    for(int i=0;i<h;i++)
        for(int j=0;j<l;j++)
            a[i][j]=false;


    for(int i=0;i<n;i++)
    {
        cin>>c>>b;
        cin>>t>>v;
        for(int i=b;i<b+v;i++)
            for(int j=c;j<c+t;j++)
                a[i][j]=true;
    }
}


    int Rect(int x,int y)
    {
        int el=l-1;
        int eh=h-1;
        int wl=l-1;
        bool tr=true;
        for(int i=x;i<h;i++)
        {
            if(a[i][y]==true){eh=i;break;}
            wl=l-1;
            tr=true;
            for(int j=y;j<l && tr==true;j++)
                if(a[i][j]==true){wl=j-1;tr=false;}
            if(wl<el)el=wl;
        }

        int fh=eh-x+1;
        int fl=el-y+1;
        return fh*fl;
    }

    void Solve()
    {
        int maxr=0;
        int work=0;
        for(int i=0;i<h;i++)
        {
            for(int j=0;j<l;j++)
                {
                    if(a[i][j]==false)work=Rect(i,j);
                    if(work>maxr)maxr=work;

                }
            work=0;
        }
        cout<<maxr<<endl;
    }

    int main ()
    {
        Init();
        Solve();
        return 0;
    }

