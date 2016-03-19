#include<iostream>
#include<algorithm>
using namespace std;
#define pp pair<int,int>
int n,m,p;
pp a[1000];
int main()
{
    cin>>n>>m>>p;

    for(int i=0;i<m;i++)
        cin>>a[i].first>>a[i].second;

    sort(a,a+m);

    cout<<"MIXED"<<endl;

//    for(int i=0;i<m;i++)
//        cout<<a[i].first<<" "<<a[i].second<<endl;

    return 0;
}
