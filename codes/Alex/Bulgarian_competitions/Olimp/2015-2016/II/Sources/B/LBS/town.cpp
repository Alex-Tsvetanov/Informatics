#include<iostream>
using namespace std;
int minmoves=0;

int main()
{
    int n, a, b; cin >> n >> a >> b;
    int roads[n][n] ;
    for (int i=0; i< n;i++)
        {for (int j=0; j< n;j++) roads[j][i] = 0;}
    while(cin){
        int p,q;
        cin>> p >> q;
        roads[p-1][q-1]=1;roads[q-1][p-1]=2;
    }

    int br1=0,br2=0;
    for(int i=0; i<n;i++) if(roads[a-1][i]!=0)br1++;
    for(int i=0; i<n;i++) if(roads[b-1][i]!=0)br2++;
    if(br1==0||br2==0){cout<< 'X'; return 0;}
    cout<<minmoves;

    return 0;
}
