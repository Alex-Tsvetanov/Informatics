#include<iostream>
using namespace std;
long long ha[2011][4000],b[30][4000],used[30],l[2011],c,g[4000];
void fun(int x)
{
    int i;
    for(i=0;i<3166;i++)
        ha[x][i]=(ha[x][i]&ha[x+1][i])^g[i];
}
int main()
{
    string s,a;
    cin>>s>>a;
    long long i,n=a.size(),j=0,c=0;
    while(a[0]!='2')
    {
        for(i=0;i<n;++i)
            if(a[i]=='1')b[i][j/64]|=1ll<<(j%64);
        g[j/64]|=1ll<<(j%64);
        j++;
        cin>>a;
    }
    for(i=0;i<s.size();++i)
        if(s[i]<='z' && s[i]>='a')used[s[i]-'a']=1;
    for(i=0;i<27;i++)
        if(used[i])used[i]=++c;
    for(i=0;i<s.size();++i)
        if(s[i]<='z' && s[i]>='a')s[i]=used[s[i]-'a']+'a'-1;
    n=s.size();
    l[0]=1;
    c=0;
    for(i=0;i<n;++i)
    {
        if(s[i]=='(')l[++c]=1;
        else if(s[i]==')')
        {
            if(l[c-1]==1)
            {
                for(j=0;j<3166;++j)
                    ha[c-1][j]=ha[c][j];
                --c;
            }
            else fun(--c);
        }
        else
        {
            if(l[c])
            {
                l[c]=0;
                for(j=0;j<3166;++j)
                    ha[c][j]=b[s[i]-'a'][j];
            }
            else
            {
                for(j=0;j<3166;++j)
                    ha[c+1][j]=b[s[i]-'a'][j];
                fun(c);
            }
        }
    }
    for(i=0;g[i/64]&(1<<(i%64));++i)
        cout<<((ha[0][i/64]>>(i%64))&1);
    cout<<'\n';
}
