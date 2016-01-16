#include<iostream>
using namespace std;
int main()
{
    int mas[10000], n, m, a, b, k, br=0;
    cin>>n;
    for(int j=0; j<n; j++) mas[j]=0;
    cin>>m;
    for(int i=0; i<m; i++)
    {
        cin>>a;
        mas[a-1]++;
        cin>>b;
        mas[b-1]++;
    }
    cin>>k;
    cout<<"\n";
    for(int i=0; i<m; i++)
    {
        if(mas[i]>=k) br++;
    }
    cout<<br<<endl;
    for(int i=0; i<m; i++)
    {
        if(mas[i]>=k) cout<<i+1<<" ";
    }
}
