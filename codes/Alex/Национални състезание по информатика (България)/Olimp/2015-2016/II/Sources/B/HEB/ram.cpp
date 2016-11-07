#include<iostream>
#include<vector>
#include<iomanip>
#include<climits>
#include<cstring>
#include<cmath>
using namespace std;
int a[10000001],b[10000001];
int main()
{
    long long k,pomk,segk,i,j,mink,br=0,segi=1;
    cin>>k;
    pomk=k/2;
    for(i=1;i<=pomk;i++)
    {
        for(j=1;j<=pomk;j++)
        {
            segk=i*(j+1)+j*(i+1);
            if(i>=j)
            {
                mink=(j*2)-1;
                if(segk-mink==k){br++;a[segi]=i;b[segi]=j;segi++;}
            }else
            {
                mink=i*2;
                if(segk-mink==k){br++;a[segi]=i;b[segi]=j;segi++;}
            }
        }
    }
    if(br==0)cout<<0<<endl;
    else
    {
        cout<<br<<endl;
        for(i=1;i<=br;i++)
        {
            cout<<a[i]<<" "<<b[i]<<endl;
        }
    }
    return 0;
}
