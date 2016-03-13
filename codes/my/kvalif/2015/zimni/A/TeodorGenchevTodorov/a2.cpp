#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct sector{
    unsigned long long b,e;
    sector(unsigned long long first,unsigned long long last)
    {
        b=first;
        e=last;
    }
};
vector<sector> systems;
bool mysrt(sector a,sector b)
{
    return a.b < b.b;
}
long long binarySearch(unsigned long long a,unsigned long long b)
{
    long long first=0,last=systems.size(),middle;
    while(first<last)
    {
        middle = (first+last)>>1;
        if(a>systems[middle].e) first = middle+1;
        else if(b<systems[middle].b) last = middle-1;
        else return middle;
    }
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    unsigned long long n,m;
    cin>>m>>n;
    for(unsigned long long i=0;i<n;++i)
    {
        unsigned long long a,b;
        cin>>a>>b;
        if(!systems.empty())
        {
            long long index = binarySearch(a,b);
            if(index>-1)
            {
                if(a<systems[index].b) systems[index].b=a;
                if(b>systems[index].e) systems[index].e=b;
            }
            else
            {
                sector temp(a,b);
                systems.push_back(temp);
            }
        }
        else
        {
            sector temp(a,b);
            systems.push_back(temp);
        }
        sort(systems.begin(),systems.end(),mysrt);
    }
    unsigned long long len = systems.size();
    for(unsigned long long i=len-1;i>0;--i)
    {
        if(systems[i-1].e>=systems[i].b)
        {
            //systems[i-1].e=systems[i].e;
            --len;
        }
    }
    cout<<len<<endl;
    return 0;
}
