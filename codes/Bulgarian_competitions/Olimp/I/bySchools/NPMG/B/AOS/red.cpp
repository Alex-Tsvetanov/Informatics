#include <iostream>
using namespace std;

int n,a[1000000],minn,maxx;

int main()
{
    cin>>n;

    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    for(int i=0;i<n;i++)
    {
        minn=a[0];
        maxx=a[n-1];

        for(int j=0;j<n;j++)
        {
            if(minn>a[j])
            {
                minn=a[j];
            }

            if(maxx<a[j])
            {
                maxx=a[j];
            }
        }
    }

    int len=0,b[100000],x=0,size_b=0;

    for(int i=0;i<n;i++)
    {
        if(minn==a[i])
        {
            for(int j=n-n+i;j<n;j++)
            {
                if(a[j]==maxx)
                {
                    len=j-i+1;
                    b[x]=len;
                    x++;
                    size_b++;
                }
            }
        }

        if(maxx==a[i])
        {
            for(int j=n-n+i;j<n;j++)
            {
                if(a[j]==minn)
                {
                    len=j-i+1;
                    b[x]=len;
                    x++;
                    size_b++;
                }
            }
        }

        len=0;
    }

    int maxxx;

    for(int i=0;i<size_b;i++)
    {
        maxxx=b[size_b-1];

        for(int j=0;j<size_b;j++)
        {
            if(maxxx<b[j])
            {
                maxxx=b[j];
            }
        }
    }

    for(int i=0;i<=n;i++)
    {
        if(a[i]==minn)
        {
            if(a[i+maxxx-1]==maxx)
            {
                cout<<i+1<<" "<<i+maxxx<<endl;
            }
        }
    }

    return 0;
}
