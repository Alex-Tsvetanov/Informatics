#include<iostream>
using namespace std;
int max1,i,n,k,m,j,tekst=1;
struct col
{
int coll;
int num;

};
col a[201][201];
void gen(int i,int j)
{
a[i][j].num=tekst;
if (a[i+1][j].coll==1 && a[i][j+1].coll==1) {return;}
else
{
 if(i+1<m && a[i+1][j].coll==0 && a[i][j].num==tekst) gen(i+1,j);
 if(j+1<n && a[i][j+1].coll==0 && a[i][j].num==tekst) gen(i,j+1);
}
}
int main ()
{
cin>>m>>n;
k=m*n;
for(i=0;i<m;i++)
for(j=0;j<n;j++) cin>>a[i][j].coll;
a[0][0].num=1;
gen(0,0);

 for(i=0;i<m;i++)
 {
    for(j=0;j<n;j++)
    {
     if(a[i][j].coll==0 && a[i][j].num==0) {tekst++;gen(i,j);}
    }
 }
 for(i=0;i<m;i++)
 {
    // cout<<endl;
    for(j=0;j<n;j++)
    {
     if(max1<a[i][j].num) max1=a[i][j].num;
     //cout<<a[i][j].num<<" ";
    }
 }
 cout<<max1<<endl;
 return 0;
 /*
 2 4 0 1 1 0 0 0 1 1

 */
}
