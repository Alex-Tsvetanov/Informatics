//Task: substrings
//Author: Kinka Kirilova-Lupanova
#include <iostream>
using namespace std;
const int MaxN = 16;

int main()
{long long  Fact[MaxN],ans;
 int i,j,n,br,m ;
 bool f=true,ff=true;
 string s,p;
 Fact[0]= 1;
 cin>>s; 
 n = s.length();
 cin>>p; 
 m=p.length();        
 for (i = 1 ;i<=MaxN;i++)
      Fact[i]= Fact[i-1]*i;
 
 for (i=0;i<p.length()-1;  i++)
     for (j=i+1;j<p.length();j++)
         if (p[i]==p[j]) f=false;
 
 for (i=0;i<p.length();i++)
      {br=0;
       for (j=0;j<s.length();j++)
         if (p[i]!=s[j]) br++;
       if (br==s.length()) ff=false; 
      }  
 ans = 0;
 if (f && ff) 
    for (i= 0;i<=n-m;i++) 
        ans=ans+ Fact[n-m]/Fact[n-m-i] * (i+1);                    
 cout<<ans<<endl;
 return 0;
}
  
  
  
  
    
  
 
