#include<iostream>
using namespace std;
int main()
{
    int m,n,i,j,br=1,q,br2=0,br3=0;int p[200][200];
    cin>>n>>m;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
        {
            cin>>p[i][j];
            if(p[i][j]==1){p[i][j]=-1;br2++;}
        }


    while((n*m)-br2>=br3)
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
            {
                if(p[i][j]==0)
                {   p[i][j]=br;br3++;
                    if(p[i][j+1]==0){p[i][j+1]=br;br3++;}
                    if(p[i][j-1]==0){p[i][j-1]=br;br3++;}
                    if(p[i+1][j]==0){p[i+1][j]=br;br3++;}
                    if(p[i-1][j]==0){p[i-1][j]=br;br3++;}
                }

                br++;
            }


    cout<<(br-(n*m))+1<<endl;
}
