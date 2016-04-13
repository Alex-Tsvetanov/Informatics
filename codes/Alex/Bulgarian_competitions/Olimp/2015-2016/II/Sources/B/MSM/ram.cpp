#include<iostream>
#include<vector>
using namespace std;
#define pp pair<int,int>

int a[100000000];
int k;
vector<pp> v;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>k;
    int i=0;

    while(a[1]<=k)
    {
        i++;

        int j=0;
        int f=(i+1)+2*i;
        a[1]=f-1;
        int d=f-i;

        while(a[j]<=k)
        {
            j++;
            if(j<=i+1)
            {
                if(j%2==1) a[j]=a[j-1]+d-1;
                else a[j]=a[j-1]+d-2;
            }
            else a[j]=a[j-1]+d;

        }

        if(a[j]==k) v.push_back(pp(i,j));

    }

    cout<<v.size()<<endl;
    for(int i=0;i<v.size();i++)
        cout<<v[i].first<<" "<<cout<<v[i].second<<endl;

    return 0;
}
