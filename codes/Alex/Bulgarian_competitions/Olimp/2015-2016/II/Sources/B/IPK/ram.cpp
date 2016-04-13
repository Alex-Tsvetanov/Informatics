#include<iostream>
#include<vector>
#include<cmath>
#define MAX 1000000
using namespace std;
int m,n,p,k;
pair<int,int> a[MAX];
int main()
{
    cin>>k;
    int i=1,br=1;
    while(i<k/2)
    {
        if(i%2==0)
        {
            if(((i+k)-(i/2))%(i+1)==0)
            {

                a[br].second=((i+k)-(i/2))/(i+1);
                a[br].first=i/2;
                br++;
            }
            i++;
        }
        else
        {
            if(((i+k)-(i/2+1))%(i+3)==0)
            {

                a[br].first=i/2+1;
                a[br].second=((i+k)-(i/2+1))/(i+3);
                br++;
            }
            i++;
        }

    }
    cout<<br-1<<endl;
    for(int j=1;j<br;j++)
    {
        cout<<a[j].first<<" "<<a[j].second<<endl;
    }
    return 0;
}
