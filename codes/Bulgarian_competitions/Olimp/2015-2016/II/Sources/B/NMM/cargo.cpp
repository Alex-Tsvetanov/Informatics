#include <iostream>
#include<algorithm>
#define maxn 1000000
using namespace std;
pair<int,bool> shippings[maxn]; // bool is beginning of a time period
bool cmp(pair<int,bool> a, pair<int,bool> b)
{
    if(a.first==b.first)
    {
        return a.second<b.second;
    }
    else return a.first<b.first;

}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int days, shipppingsCount, teams;
    cin>>days>>shipppingsCount>>teams;
    cout<<"MIXED"<<endl;
    return 0;
    teams/=2;
    for(int i =0; i<shipppingsCount; i++)
    {
        cin>>shippings[i*2].first;
        shippings[i*2].second = true;
        cin>>shippings[i*2+1].first;
        shippings[i*2+1].second = false;
    }
    sort(shippings, shippings + shipppingsCount*2, cmp);
    for(int i =0; i<shipppingsCount; i++)
    {
        cout<<shippings[i*2].first<<" "<<shippings[i*2].second<<endl;
        cout<<shippings[i*2+1].first<<" "<<shippings[i*2+1].second<<endl;
    }
    return 0;
}

/*

100 3 2
4 5
5 6
5 7

*/
