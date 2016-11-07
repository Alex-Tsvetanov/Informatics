///Simeon Atanasov Atanasov 7a MG
///NOI-2 2016 C2. Redici
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
int p,n,s;
int brn=1,sum=0;
int i,j,k;
string t="";
///int num[30]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29};
int main ()
{
    cin >> p >> n >> s;
    for(i=1;i<=n;i++)
    {
        sum=i;
        for(j=0;j<n,sum;j++)
        {
            t=t+(char)1;
            sum--;
        }
        for(;j<n;j++)
        {
            t=t+(char)0;
        }
        sort(t.begin(),t.end());
        do
        {
            brn++;
        }
        while(next_permutation(t.begin(),t.end()));
    }
    cout << brn << endl;
    return 0;
}
