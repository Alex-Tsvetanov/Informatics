#include <cstdio>
#include <string>
using namespace std;
long long n, bitemask[25][505];
long long upper_two (long long n)
{
    if (n==2) return 1;
    long long br=1, stepen=2;
    while (1)
    {
        if (stepen<n)
        {
            stepen*=2;
            br++;
        }
        else
        {
            return br;
            break;
        }
    }

}
string nbinum (long long s, long long len)
{
    string t;
    if (s!=0)
    {
        while (1)
        {
            if (s==0) break;
            if (s%2==0) t="0"+t;
            else t="1"+t;
            s/=2;
        }
    }
    else t="0";
    while (t.size()<len) t="0"+t;
    return t;
}
int main ()
{
    scanf ("%lld",&n);
    upper_two(n);
    long long k=upper_two(n);
    printf ("%lld\n",k);
    long long m=k;
    if (n>500) return 0;
    for (int i=1; i<=n; i++)
    {
        string rez=nbinum(i-1,k);
        for (int j=1; j<=k; j++)
        {
            bitemask[j][i]=rez[j-1]-'0';
        }
    }
    for (int i=1; i<=k; i++)
    {
        int tmp=0;
        for (int j=1; j<=n; j++)
        {
            if (bitemask[i][j]) tmp++;
        }
        printf ("%d ",tmp);
        for (int j=1; j<=n; j++)
        {
            if (bitemask[i][j]) printf("%d ",j);
        }
        printf ("\n");
        tmp=0;
    }
    return 0;
}
