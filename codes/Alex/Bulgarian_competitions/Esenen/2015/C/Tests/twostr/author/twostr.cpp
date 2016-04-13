//Task: twostr
//Author: Kinka Kirilova-Lupanova

#include <iostream>
#include <algorithm>
using namespace std;

int n,m, a[6000],b[6000], c[6000];

void convert(string s, int a[])
{int n=s.length();
 int i=n-1, j=0;
 while(j<n)
   {a[j]=s[i]-'0'; i--; j++;}
}

int Compare(int a[], int b[])
{int i;
 if (n<m) return -1;
 else 
      if (n>m) return 1;
 for (i=n-1;i>=0;i--)
     if (a[i]<b[i]) return -1;
     else 
          if (a[i]>b[i]) return 1;
 return 0;
}          

void sub(int a[], int b[],int &t)
{int i, p=0,r;
 if (n>m) t=n;
 else t=m;
 for (i=0;i<=t;i++) c[i]=0;    
 for (i=0;i<t;i++)
     {c[i]=a[i]-b[i]-p;
      if (c[i]<0) {c[i]=c[i]+10;p=1;}
      else p=0;
     }
 while (c[t-1]==0) t--;
 if (t<1) t=1;
}


int main()
{  int i,p;
   string   s, t,x,y;
   cin>>s;
   n=s.length();
   x=s;
   cin>>t;
   m=t.length();
   y=t;
   s=s+s;
   t=t+t;
   for (i = 1; i < n; i++)
       { string h = s.substr(i,n);
         if (h[0]!='0' && h>x) x=h;
       }  
  
  for (i = 1; i < m; i++)
       { string h = t.substr(i,m);
         if (h[0]!='0' && h<y) y=h;
       }  
  
  convert(x,a);
  convert(y,b);
  if (Compare(a,b)>=0) sub(a,b,p);
  else {cout<<"-";sub(b,a,p);}
  for (i=p-1;i>=0;i--) cout<<c[i];
    cout<<endl;
    return 0;
}
