#include<cstdio>
using namespace std;

const int N=1000002;

int n;
int a[N];

int main()
{
  scanf("%d",&n);
  for(int i=0;i<n;i++) scanf("%d",&a[i]);

  for(int i=0;i<n;i++)
  {
    int c=a[i];
    bool L=true;
    for(int j=i+1;j<n;j++) if(a[j]>c){L=false; break;}
    if(L){if(i<n-1) printf("%d ",c); else printf("%d\n",c);}
   }
}
