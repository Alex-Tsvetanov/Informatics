#include <stdio.h>
#include <algorithm>
using namespace std;

const int nmax=100001;
struct rowEl {
  int value;
  int index;
};
rowEl a1[nmax];
rowEl a2[nmax];
int a1Count;
int a2Count;

rowEl p1[nmax];
rowEl p2[nmax];
int pCount;


bool compareValue(rowEl x, rowEl y)
{
  return x.value<y.value;
}

bool compareIndex(rowEl x, rowEl y)
{
  return x.index<y.index;
}

void input()
{
  scanf("%d",&a1Count);
  for (int i=1;i<=a1Count;i++) {
    scanf("%d",&a1[i].value);
    a1[i].index=i;
  }
  scanf("%d",&a2Count);
  for (int i=1;i<=a2Count;i++) {
    scanf("%d",&a2[i].value);
    a2[i].index=i;
  }
}

bool solve()
{
    sort(a1+1,a1+a1Count+1,compareValue);
    sort(a2+1,a2+a2Count+1,compareValue);
    pCount=0;
    int uka1=1;
    int uka2=1;
    while ((uka1<=a1Count) && (uka2<=a2Count))
    {
      if (a1[uka1].value==a2[uka2].value)
      {
          pCount++;
          p1[pCount]=a1[uka1];
          p2[pCount]=a2[uka2];
          uka1++; uka2++;
      }
      else
      {
          if (a1[uka1].value<a2[uka2].value) uka1++;
          else uka2++;
      }
    }
    if (pCount==0) return true;
    sort(p1+1,p1+pCount+1,compareIndex);
    sort(p2+1,p2+pCount+1,compareIndex);
    bool flag=true;
    for (int i=1;i<=pCount;i++)
        if (p1[i].value!=p2[i].value){
            flag=false;
            break;
        }
    return flag;
}

int main()
{
    for (int i=1;i<=5;i++)
    {
        input();
        if (solve()) printf("1");
        else printf("0");
    }
    printf("\n");
}
