#include <iostream>

using namespace std;

int cross[80000][80000];
int n;
int p,q;
int begc,endc;
int lawbreaks=0,minlawbreaks=200001;
int pathl=1;
int path[200001];
bool fl=false;

bool visited(int x)
{
    for(int i=1;i<=pathl;i++)
        if(path[i]==x)return true;
    return false;
}

void find_path(int a,int b)
{
    if(a==b)
    {
        if(lawbreaks<minlawbreaks)
            minlawbreaks=lawbreaks;
        fl=true;
    }
    else
    {
        for(int i=1;i<=n;i++)
        {
            if(cross[a][i]==1)
            {
                if(visited(i)==false)
                {
                    pathl++;
                    path[pathl]=i;
                    find_path(i,b);
                    pathl--;
                }
            }
            if(cross[a][i]==2)
            {
                if(visited(i)==false)
                {
                    pathl++;
                    lawbreaks++;
                    path[pathl]=i;
                    find_path(i,b);
                    pathl--;
                    lawbreaks--;
                }
            }
        }
    }
}

int main()
{
    cin>>n;
    cin>>begc>>endc;
    for(;cin>>p>>q;)
    {
        cross[p][q]=1;
        cross[q][p]=2;
    }
    path[1]=begc;
    find_path(begc,endc);
    if(!fl)cout<<"X"<<endl;
    else cout<<minlawbreaks<<endl;

    return 0;
}
/*
4 1 4
4 3
3 2
1 2
4 2
*/
