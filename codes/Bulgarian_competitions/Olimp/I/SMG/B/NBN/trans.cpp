#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
long cities[100000000]={0};
int main()
{
    int p;
    int m;
    int k;
    int tempa,tempb;
    cin>>p>>m;
    for(int i = 0;i < m;i++)
    {
        cin>>tempa>>tempb;
        cities[tempa]++;
        cities[tempb]++;
    }
    cin>>k;
    vector<int> res;
    for(int i = 0;i < p;i++)
        if(cities[i] >= k)
            res.push_back(i);
    cout<<res.size()<<endl;
    for(int i = 0;i < res.size();i++)
        cout<<res[i]<<" ";
    if(res.size()!=0)
        cout<<endl;
    return 0;
}

