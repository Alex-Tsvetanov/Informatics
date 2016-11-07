#include<iostream>
using namespace std;
int main ()
{
    int x,y,c[40001],br=1,i,f=0,brf=1;
    cin >> x >> y;
    for(i=1;i<=x*y;i++)
    {
        cin >> c[i];
        if(c[i]==1)
        {
            c[i]==-1;
            brf++;
        }
    }
    c[1]=1;
    for(i=1;i<=x*y;i++)
    {
        if(c[i]==br)
        {
            if((c[i+1]==0)&&(i%x!=0))
            {
                c[i+1]=br;
                f++;
                brf++;
            }
            if((c[i-1]==0)&&(i%x!=1))
            {
                c[i-1]=br;
                f++;
                brf++;
            }
            if((c[i+x]==0)&&(i<y))
            {
                c[i+x]=br;
                f++;
                brf++;
            }
            if((c[i-x]==0)&&(i>1))
            {
                c[i-x]=br;
                f++;
                brf++;
            }
            if(f==0)
            {
                if(brf==x*y){cout << br << endl;return 0;}
                br++;
                i=2;
                for(int j=3;j<=x*y;j++)
                {
                    if(c[j]==0){c[j]=br;break;}
                }
            }
            f=0;
        }
    }
    return 0;
}
