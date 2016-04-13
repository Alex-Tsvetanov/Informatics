#include<iostream>
using namespace std;
int f[100][100]={0};
int l,h,n,a[100],b[100],c[100],d[100],br=0,br1=0,o=0,g=0,bgt=0;

int main(){
int max=0;
cin>>l>>h>>n;
for(long long int i=0;i<n;i++)
{cin>>a[i]>>b[i]>>c[i]>>d[i];
for(int j=b[i];j<b[i]+d[i];j++)
{for(int k=a[i];k<a[i]+c[i];k++)
{f[j][k]=1;
}
}
}

for(int j=0;j<h;j++)
{for(int k=0;k<l;k++)
{g=k;
o=j;
br=1;
br1=1;
bgt=0;
while(f[o][k]!=1)
{if(o==h-1) break;
o++;
br++;
}
while(f[g][j]!=1)
{if(g==l-1) break;
g++;
br1++;}
for(int j1=j;j1<j+br;j1++)
{for(int k1=k;k1<k+br1;k1++)
{if(f[j1][k1]==1) bgt++;
}
}if(bgt==0) {if(max<br*br1) max=br*br1;}
}}
cout<<max<<endl;
return 0;
}
