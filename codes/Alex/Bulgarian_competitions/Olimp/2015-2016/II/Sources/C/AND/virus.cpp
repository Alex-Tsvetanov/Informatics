#include<iostream>
using namespace std;
int a[502][502],i,k=1,ind[502],j;
long long n,tmp=1;
bool fl=false;
 int main()
 {
 ios::sync_with_stdio(0);
 cin.tie(0);
 cout.tie(0);
 cin>>n;
 n--;
 if(n>499)
 {
     tmp=0;
     while(true)
 {
     if(tmp>=n)break;
     ///cout<<tmp<<" ";
     tmp++;
     tmp=tmp+k-1;
     if(tmp>=n)break;
     ///cout<<tmp<<" ";
     k++;
 }
 cout<<k<<"\n";
 return 0;
}
 while(true)
 {
     a[k][ind[k]]=tmp;
     ind[k]++;
     if(tmp==n)break;
     tmp++;
     for(i=k-1;i>=1;i--)
     {
         a[k][ind[k]]=tmp;
         a[i][ind[i]]=tmp;
         ind[k]++;
         ind[i]++;
         if(tmp==n)
         {
             fl=true;
             break;
         }
         tmp++;
     }
     if(fl)break;
     k++;
 }
 cout<<k<<"\n";
 for(i=1;i<=k;i++)
 {
     cout<<ind[i]<<" "<<a[i][0];
     for(j=1;j<ind[i];j++)
     {
         cout<<" "<<a[i][j];
     }
     cout<<"\n";
 }
 return 0;
}
