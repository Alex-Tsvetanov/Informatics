#include<bits/stdc++.h>
#include<algorithm>
#define MAXK 32
#define endl '\n'
using namespace std;

short mas[MAXK]= {0},p,n,s,i,j,z,razlika,br_chisla,q;
long long br,br2,dk,f1,f2,f3,f4,y,m;

int i_sequence(int i, int n)
{
    if(i==0)return 1;
    if(i==1)return n;
    br2=0;
    z=0;
    short q;
    if((i+1)<=p)q=(i+1);
    else q=p;
    for(j=1; j<q; ++j)
    {
        br_chisla=0;
        z=j;
        razlika=i-z;
        while(razlika)
        {
            razlika=i-z;
            if(razlika>z && razlika<(2*z))
            {
                br_chisla++;
                break;
            }
            else
            {
                z+=j;
                br_chisla++;
            }
        }
        if(br_chisla<=n)
        {
            f1=1;
            f2=1;
            f3=1;
            for(y=2; y<=n; ++y)
            {
                f1*=y;
            }
            for(y=2; y<=br_chisla; ++y)
            {
                f2*=y;
            }
            for(y=2; y<=(n-br_chisla); ++y)
            {
                f3*=y;
            }
            m=f2*f3;
            f4=f1/m;
            br2+=f4;
        }
    }
    return br2;
}

int main()
{
    scanf("%hd%hd%hd",&p,&n,&s);
    if(n==1)
    {
        short k;
        k=min(p,s)-1;
        printf("%hd",k);
    }
    if(n==2)
    {
        short k;
        s--;
        k=min(s,p);
        printf("%hd",k);
    }
    else
    {
        for(i=0; i<s; ++i)
        {
            br+=i_sequence(i,n);
        }
        printf("%lld\n",br);
    }
    return 0;
}
