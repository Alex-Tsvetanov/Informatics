#include<iostream>
#include<vector>
using namespace std;
vector<int> apples;
vector<int> jumps;
vector<int> possible;
vector<int> index;
vector<int> dyn;
int n;
int m;
void jump(int x,long long sum)
{
    if(dyn[x] > sum)
        return;
    dyn[x] = sum;
    sum+=apples[x];
    for(int i = 0;i < jumps.size();i++)
    {
        if(x+jumps[i] > n)
        {
            possible.push_back(sum);
            index.push_back(x);
        }
        else
            jump(x+jumps[i],sum);
    }
    return;
}
int main()
{
    cin>>n>>m;
    int enter;
    for(int i = 0;i < m;i++)
    {
        cin>>enter;
        jumps.push_back(enter);
    }
    for(int i = 0;i <= n;i++)
    {
        cin>>enter;
        apples.push_back(enter);
    }
    for(int i = 0;i <= n+1;i++)
        dyn.push_back(-1);
    jump(0,0);
    int indexMax = 0;
    for(int i = 1;i < possible.size();i++)
    {
        if(possible[i] == possible[indexMax] && index[i] < index[indexMax])
            indexMax = i;
        if(possible[i] > possible[indexMax])
            indexMax = i;
    }
    cout<<possible[indexMax]<<" "<<index[indexMax];
    return 0;
}
