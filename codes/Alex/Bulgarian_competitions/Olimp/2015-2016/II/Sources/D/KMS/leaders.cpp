#include<iostream>
using namespace std;
long long chisla[1000000], n, leaders[1000000], poredno=0, target;

bool check(int i)
{
    target=chisla[i];
    for(int j=i; j<n; j++)
    {
        if(target<chisla[j])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>chisla[i];
    }
    for(int i=0; i<n; i++)
    {
        if(check(i)==true)
        {
            leaders[poredno]=chisla[i];
            poredno++;
        }
    }
    for(int i=0; i<poredno; i++)
    {
        if(!(i+1==poredno)){
            cout<<leaders[i]<<" ";
        }else{
            cout<<leaders[i];
        }
    }
    cout<<endl;
    return 0;
}
