#include <cstdio>
#include <algorithm>
#include <string>
using namespace std;
long long brperm (string s)
{
    long long br=0;
    do
    {
        br++;
    }while (next_permutation(s.begin(),s.end()));
    return br;
}
long long brrow=0;
int main ()
{
    int p, n, s;
    scanf ("%d%d%d",&p,&n,&s);
    if (p==1 && s==0) printf ("1\n");
    else if (p==1 && s>0) printf ("0\n");
    else if (p==2)
    {
        string t;
        t.resize(n,'0');
        brrow++;
        int tmp=0;
        for (int i=t.size()-1; i>=0; i--)
        {
            if (tmp==s-1) break;
            t[i]='1';
            tmp++;
            brrow+=brperm(t);
        }
        printf ("%d\n",brrow);
    }
    return 0;
}
