#include<cstdio>
using namespace std;

const int N=1000002;

int n;
int a[N];
int b[N];
int c;

void Leaders()
{

 c=-1;
 int currentLeader = a[n - 1];
 for (int i = n - 1; i >= 0; i--)
   if(a[i] >= currentLeader)
    {
       currentLeader = a[i];
       c++; b[c]=currentLeader;
    }
}

int main()
{
  scanf("%d",&n);
  for(int i=0;i<n;i++) scanf("%d",&a[i]);
  Leaders();
  printf("%d",b[c]);
  for(int i=c-1;i>=0;i--) printf(" %d",b[i]);
  printf("\n");
}
