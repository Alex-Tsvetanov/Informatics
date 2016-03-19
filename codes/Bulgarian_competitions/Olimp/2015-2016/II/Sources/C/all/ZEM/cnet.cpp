#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector <int> v[3002],vo;
int n,m;
queue <int> q;

int bfs(int vr)
{
int fl[3002]={},i,tek,tek2,step=0,neww=1,sum=-1;
fl[vr]=1;
q.push(vr);
while (!q.empty())
    {
     step++;
     tek=q.front();
     for (i=0; i<v[tek].size(); i++)
        {
         tek2=v[tek][i];
         if(!fl[tek2]) {fl[tek2]=1; q.push(tek2);}
        }
     //cout <<tek<<" "<<neww<<" "<<step<<" ";
     if (step==neww) {sum++; neww+=q.size()-1;}
     //cout <<sum<< endl;
     q.pop();
    }
if (step==n) return sum;
else return -1;
}

int main()
{
int i,j,a,b,res,minp=999999,sum=0;
cin >>n>>m;
for (i=1; i<=m; i++)
    {
     cin>>a>>b;
     v[a].push_back(b);
    }
for (i=0; i<n; i++)
    {
     res=bfs(i);
     if(res>-1)
         {
          if (res<minp)
             {
              vo.clear();
              vo.push_back(i);
              minp=res;
              sum=1;
             }
         else if (res==minp) {vo.push_back(i); sum++;}
         }
    }
cout <<sum<< endl;
for (i=0; i<vo.size()-1; i++) cout <<vo[i]<<" ";
cout <<vo[i]<< endl;
return 0;
}
/*
8 13
0 1
0 2
1 3
3 0
7 1
3 5
4 1
4 5
7 5
5 2
5 6
4 7
7 4
*/

/*
6 9
5 1
5 3
4 0
3 5
2 3
1 2
1 0
1 4
0 5
*/
