#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;
bool whole(float f)
{int f1=f;
if(float(f1)==f) return 1;
return 0;
}
struct pairr
{int n;
int m;
};
bool cmp(pairr a, pairr b)
{if(a.m>b.m) return 1;
return 0;
}
int main()
{float k;
float f,f0=0.0;
pairr p;
cin>>k;
vector<pairr> v;
int i;
for(i=1;i<=sqrt((k-1)/2);i++)
{//ako e N
f=(k-1+i)/(2*i+1);
if(whole(f)) {/*cout<<f<<"////"<<i<<endl;*/p.n=i;p.m=f;v.push_back(p);}
//ako e M
f=(k+i)/(2*i+1);
if(whole(f)) {/*cout<<f<<"///"<<i<<endl;*/p.m=i;p.n=(int)f;v.push_back(p);}
}
for(i;i<sqrt(k/2);i++)
{f=(k+i)/(2*i+1);
if(whole(f)) {p.m=i;p.n=(int)f;v.push_back(p);}
}
cout<<v.size()<<endl;
//if(v.size()==0)
//{for(i=0;i<=v.size()-1;i++)
//{cout<<v[i].m<<" "<<v[i].n<<endl;
//}
//}
if(v.size()>0)
{pairr mas[v.size()];
for(i=0;i<=v.size()-1;i++)
{mas[i]=v[i];
}
sort(mas,mas+v.size(),cmp);
for(i=0;i<=v.size()-1;i++)
{cout<<v[i].m<<" "<<v[i].n<<endl;
}
}
return 0;
}
