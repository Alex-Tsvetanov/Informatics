#include<iostream>
#include<string>
using namespace std;
char pole[101][101];
int main()
{
    int m,n,kon=0,sum=0,trmi=0,trmi2=0;
    cin>>n>>m;
    bool a[m];
    for(int N=0; N<n; N++)
    {
        for(int M=0; M<m; M++)
        {
            a[M]=false;
            cin>>pole[N][M];
            if(pole[N][M]=='*')
            {
                a[M]=true;
                trmi++;
            }
        }
        if(trmi==m)
        {
            kon++;
        }
        if(trmi!=m)
        {
            sum=sum+kon*(kon+1)/2;
            kon=0;
        }
        trmi=0;
    }
    sum+=kon*(kon+1)/2;
    cout<<sum<<endl;
    return 0;
}
