#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main( )
{
    long long n;
    int k,i,j,t,q;
    vector<int> v[11];
    string s[501];
    cin>>n;
    j=0;
    i=1;
    while(i<n)
    {
        i=i<<1;
        j++;
    }
    cout<<j<<endl;
    if(n<500)
    {
        for(i=0;i<n;i++)
        {
            t=1<<(j-1);
            while(t>0)
            {
                if(i&t)s[i]=s[i]+'1';
                else s[i]=s[i]+'0';
                t=t>>1;
            }
        }
       for(i=0;i<n;i++)
       {
           for(k=0;k<s[i].size();k++)
           {
               if(s[i][k]=='1')
               {
                   v[k+1].push_back(i);
               }
           }
       }
       for(i=1;i<=j;i++)
       {
           t=v[i].size( );
           cout<<t<<" ";

           for(k=0;k<t-1;k++)
           {
               cout<<v[i][k]<<" ";
           }
           cout<<v[i][t-1]<<endl;
       }
    }
}
