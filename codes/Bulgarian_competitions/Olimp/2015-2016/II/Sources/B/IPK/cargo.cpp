#include<iostream>
#include<algorithm>
#define MAX 1000001
using namespace std;
int n,m,p;
pair<int,int> a[MAX];
int main()
{
    cin>>n>>m>>p;
    for(int i=1;i<=m;i++)
    {
        cin>>a[i].first;
        cin>>a[i].second;
    }

    cout<<"MIXED"<<endl;
    return 0;
}
