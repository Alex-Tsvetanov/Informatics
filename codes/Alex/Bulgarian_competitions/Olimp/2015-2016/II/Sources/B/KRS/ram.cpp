#include  <iostream>
#include  <iomanip>
#include  <cstdlib>
#include  <cmath>
#include  <string>
#include  <cstring>
#include  <vector>
#include  <list>
#include  <stack>
#include  <algorithm>
#include  <queue>
#include  <fstream>
using  namespace  std;

int main()

{
    ios_base::sync_with_stdio(false);
    long long int m,n,k,p,s;
    cin>>k;
    int br=0;
    int i=1;
    int a[100000],b[100000],c[100000];
    s=k+1;
    int x=-1;
    int ppp=sqrt(k);
    while(i<=ppp)
    {
        for(int j=1; j<=sqrt(k)+i; j++)
        {
            for(int f=1; f<=sqrt(k)+i; f++)
            {
                if((2*j+2*f+(j-1)*f+(f-1)*j)==s)
                {
                    br++;
                    x++;
                    a[x]=j;
                    b[x]=f;
                    c[x]=s;
                }
            }
        }
        i++;
        s++;
    }
if (br==0){cout<<0; return 0;}
    int br1=0;
    for(int j=0; j<=x; j++)
    {
        //int d[a[x]][b[x]];
        int q= max(a[j],b[j]);
        int v=1,z=1;
        br1=0;
        while(v<=a[j] && z<=b[j])
        {
z++;
            if(z>b[j]){br1++; break;}
            br1++;
            v++;
            if(v>a[j]){br1++; break;}
            br1++;

        }cout<<c[j]<<" "<<br1<<endl;
        if(c[j]-br1==k)
        {
            if(br==0)
            {
                cout<<0;
                return 0 ;
            }
            else
            {
                cout<<br<<endl;
                for(int l=0; l<=x; l++)
                {
                    cout<<a[l]<<" "<<b[l]<<endl;

                }
            }
        }
    }



    return 0;


}
