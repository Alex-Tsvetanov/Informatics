#include <cstdio>
using namespace std;
int n,m,a[200],b[200001];
int vav()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i=0;i<=n;i++)
    {
        scanf("%d",&b[i]);
    }
}

int cec()
{
    int q,c[m],br[m],l;
    for(int i=0;i<m;i++)
    {
        c[i]=0;
        for(int j=0;j<n;j+=a[i])
        {
            c[i]+=b[j];
            br[i]=j;
        }
    }
    q=c[0];
    l=br[0];
    for(int i=1;i<m;i++)
    {
        if(q<c[i])
        {
            q=c[i];
            l=br[i];
        }
        else if(q==c[i]&&l>br[i])
        {
            q=c[i];
            l=br[i];
        }
    }
    printf("%d %d",q,l);
}

int main()
{
    vav();
    cec();
    return 0;
}
