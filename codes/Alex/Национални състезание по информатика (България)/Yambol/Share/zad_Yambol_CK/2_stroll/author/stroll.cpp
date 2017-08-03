#include<bits/stdc++.h>
#include <stdio.h>
#include <iostream>
#include <string.h>
#define MAXN 200

using namespace std;

struct verses{
              int dist;
              int lnh;
              char rpnt[MAXN];
}res[1000];
int n, sv, ev, maxd;
int A[MAXN][MAXN];
char used[MAXN];
int path[MAXN], npaths = 0, cnt;
int cmp(const void *a,const void *b)
{
  verses *c, *d;
  c=(verses *)a;
  d=(verses *)b;
  if(c->dist > d->dist) return 1;
  if(c->dist < d->dist) return -1;
  return(strcmp((*c).rpnt,(*d).rpnt));
}
void findPaths(void)
{ int k, s;
  s=0;
  for (k = 0; k < cnt; k++) s += A[path[k]][path[k+1]];
  if(s<=maxd){
    res[npaths].dist = s;
    for(k = 0; k <= cnt; k++){
       res[npaths].rpnt[k]= path[k]+1;
    }
    res[npaths].lnh = cnt;
    npaths++;
  }
  return;
}
void allDFS(int i, int j)
{ int k;
  if(i == j){
    path[cnt] = j;
    findPaths();
    return;
  }
  used[i] = 1;
  path[cnt++] = i;
  for(k = 0; k < n; k++)  /* рекурсия за всички съседи на i */
     if(A[i][k] && !used[k]) allDFS(k, j);
  /* връщане: размаркирване на посетеният връх */
  used[i] = 0; cnt--;
}
int main(void){
  int m, i, k;
  cnt = 0;
  cin >> n >> m;
  for(k = 0; k < n; k++){
      used[k] = 0;
      for(i=0; i<n; i++) A[k][i] = 0;
  }
  for(i = 0; i < m; i++ ){
     int u, v, d;
     cin >> u >> v >> d;
     u--; v--;
     A[u][v] = A[v][u] = d;
  }
  cin >> sv >> ev >> maxd;
  allDFS(sv-1, ev-1);
  if( npaths > 0){
    qsort(res, npaths,sizeof(verses),cmp);
    for(i=0; i<npaths; i++){
       printf("%u:", res[i].dist);
       for(k=0; k<=res[i].lnh; k++)
       printf(" %u", res[i].rpnt[k]);
       printf("\n");
    }
  }
  else printf("There are no suitable routes\n");
  return 0;
}
