#include<iostream>
using namespace std;


int main()
{
    long long n,beg,endd;
    int m,p,i,f;
    bool mixed = false,imp = false;
    cin>>n>>m>>p;
    long long den[n];
    for(i=0;i<n;i++)
    {
        den[i]=0;
    }
    for(i=0;i<m;i++)
    {
        cin>>beg>>endd;
        if (endd > n)
        {
            endd=m;
        }
        for(f=beg;f<endd;f++)
        {
            if((f+1)%7==0)
            {
                f=f+2;
            }
            if(den[f]<p/2)
            {
                den[f]++;
                break;
            }
        }
        if(f>=endd)
        {
            mixed = true;
            for(f=beg-(beg%7)+6;f<endd;f++)
            {
                if(den[f]<p/2)
                {
                    den[f]++;
                    break;
                }
                if(f%7==0)
                {
                    f=f+5;
                }
            }

        }
        if(f>=endd)
        {
            imp = true;
            //cout<<"IMPOSSIBLE";
            break;
        }

    }
    if (imp)
    {
        cout<<"IMPOSIBLE"<<endl;
    }
    else if(i>=m)
    {
        if(mixed)
        {
            cout<<"MIXED"<<endl;
        }
        else
        {
            cout<<"OK"<<endl;
        }
    }


    return 0;
}
