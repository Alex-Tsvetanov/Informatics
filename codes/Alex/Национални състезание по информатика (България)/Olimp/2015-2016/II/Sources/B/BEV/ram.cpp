#include<iostream>
#include<vector>
using namespace std;
long long k,br,flag;
vector <pair <long long, long long> > v;
long long formula1(int x, int y)
{
    return 2*x*y+y-x;
}
long long formula2(int x, int y)
{
    return 2*x*y+x-y+1;
}
void findbtw(int x,int y)
{
    int flagg=0;
    int l=y-1000,r=y,sreda=0;
    for(long long j=y-1000; j<=y;j++)
    {
        if(j<=0)j=1;
        //sreda=(l+r)/2;
        if(x<j)
        {
            if(formula1(x,j)==k)
            {
                v.push_back(make_pair(x,j));
                br++;
                flagg=1;
                break;
            }
        }
        else
        {
            if(formula2(x,j)==k)
            {
                v.push_back(make_pair(x,j));
                br++;
                flagg=1;
                break;
            }
        }
    }
}
int main()
{
    cin>>k;
    for(int i=1;; i++)
    {
        flag=0;
        for(int j=1;; j+=1000)
        {
            if(i<j)
            {
                if(formula1(i,j)==k)
                {
                    v.push_back(make_pair(i,j));
                    br++;
                    break;
                }
                if(formula1(i,j)>k)
                {
                    //cout<<i<<" "<<j<<endl;
                    findbtw(i,j);
                    if(j==1)
                    {
                        flag=1;
                    }
                    break;
                }
            }
            else
            {
                if(formula2(i,j)==k)
                {
                    v.push_back(make_pair(i,j));
                    br++;
                    break;

                }
                if(formula2(i,j)>k)
                {
                    // cout<<formula2<<" "<<i<<" "<<j<<endl;
                    if(j==1)
                    {
                        flag=1;
                    }
                    findbtw(i,j);
                    break;
                }
            }

        }
        if(flag==1)break;
    }
    cout<<br<<endl;
    for(int i=0; i<br; i++)
    {
        cout<<v[i].first<<" "<<v[i].second<<endl;
    }
    return 0;
}
