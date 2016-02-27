#include<cstdio>
#include<cstdlib>
#include<ctime>


int main(int na, char *a[])
{
  srand(1);
  int m=atoi(a[1]);
  int n=atoi(a[2]);
  printf("%d %d\n",m,n);
  printf("%d %d\n",atoi(a[3]),atoi(a[4]));
  for(int i=1;i<=m;i++)
  {
    printf("%d",rand()%100-40);
    for(int j=2;j<=n;j++) 
     printf(" %d",rand()%100-40);
    printf("\n");
  }
}

