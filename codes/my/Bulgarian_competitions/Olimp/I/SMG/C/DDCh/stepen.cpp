#include <iostream>
#include <map>
#include <utility>
#include <algorithm>
#include <vector>

using namespace std;

uint32_t x, cp;
map<uint32_t, uint32_t> razlagane;
vector<pair<uint32_t, uint32_t>> otg;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>x;
    otg.reserve(10);
    cp=x;
    while(x%2==0)
    {
        razlagane[2]++;
        x/=2;
    }
    for(uint32_t i = 3; i*i<=cp; i+=2)
    {
        while(x%i==0)
        {
            razlagane[i]++;
            x/=i;
        }
    }
    if(razlagane.size()>0)
    {
        for(uint32_t i = 2; i*i<=cp;)
        {
            int n = 1;
            for(auto &p:razlagane)
            {
                if(p.second%i!=0)
                {
                    goto GO;
                }
                else
                {
                    for(uint32_t j=0; j<p.second/i; j++)
                    {
                        n*=p.first;
                    }
                }
            }
            otg.push_back({n, i});
GO:
            i++;
        }
    }
    cout<<otg.size()<<'\n';
    sort(begin(otg), end(otg), greater<pair<uint32_t,uint32_t>>());
    for(auto &sq:otg)
    {
        cout<<sq.first<<" "<<sq.second<<'\n';
    }
    return 0;
}
