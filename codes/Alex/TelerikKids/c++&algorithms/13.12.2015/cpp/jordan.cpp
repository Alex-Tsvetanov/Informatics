#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int s[100];
    int m,n;
    cin>>m>>n;
    for(int i=0;i<m;i++)
    {
        s[i]=i;
    }
    for(int i=0;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        if(a>b)
        {
            int x=b;
            while(s[x]!=x)
            {
                x=s[x];
            }
            s[a]=x;
        }
        else
        {
            int x=a;
            while(s[x]!=x)
            {
                x=s[x];
            }
            s[b]=x;
        }
    }
    for(int i=0;i<m;i++)
    {
        s[i]=s[s[i]];
    }
    for(int i=0;i<m;i++)
    {
        cout<<s[i]<<" ";
    }
    sort(s,s+m);
    int c=1;
    for(int i=1;i<m;i++)
    {
       if(s[i]!=s[i-1])
       {
           c++;
       }
    }
    cout<<"\n"<<c<<"\n";
    main();
}
