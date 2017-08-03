//Task: mss
//Author: Kinka Kirilova-Lupanova
#include <iostream>
#include <stdio.h>
using namespace std;

const int maxN=40;
int  can[maxN+1], n;
int ans;

void check()
{ans++;
}

void find(int i)
{int old[maxN+1], j;
  if (i>=n) 
    {check();
     return ;
    }
  if (can[i]==-1) 
    {find(i+1);
     return;
    }
  can[i]=0;
  find(i+1);
  if (can[(i+i) % n]==1) return;
  for (int p=1;p<=n;p++) 
       old[p]=can[p]; 
  can[i]=1;
  for (j=1; j<=i;j++) 
    if (can[j]==1) 
      {can[(j+i) % n]=-1;
       can[(j-i+n) % n]=-1;
       can[(i-j+n) % n]=-1;
      }
  find(i+1);
    for (int p=1;p<=n;p++) 
       can[p]=old[p]; 
}
          int main()
{ scanf("%d",&n);
  find(1);
  printf("%d\n",ans);
	return 0;
}
