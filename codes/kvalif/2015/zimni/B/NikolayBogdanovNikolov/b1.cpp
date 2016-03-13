#include<iostream>
using namespace std;
int table[1001][1001];
int main()
{
    int demanswers = -100200100;
    int mb,nb,m,n;
    cin>>mb>>nb>>m>>n;
    for(int i = 0;i < mb;i++)
        for(int j = 0;j < nb;j++)
            cin>>table[i][j];
    for(int i = 0;i <= mb-m;i++)
        for(int j = 0;j <= nb-n;j++)
        {
            int sum=0;
            for(int i1 = i;i1 < i+m;i1++)
                for(int j1 = j;j1 < j+n;j1++)
                    sum+=table[i1][j1];
            demanswers = max(demanswers,sum);
        }
    cout<<demanswers<<endl;
    return 0;
}
