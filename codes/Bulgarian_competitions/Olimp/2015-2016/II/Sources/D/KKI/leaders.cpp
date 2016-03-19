#include<iostream>
using namespace std;
long long mas[1000000];
int main()
{
    int n,result=0;
    cin>>n;
    for(int i=0;i<n;i++)cin>>mas[i];
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(mas[j]>mas[i]){i=j-1;break;}
            if(j==n-1&&mas[j]<mas[i])cout<<mas[i]<<" ";
        }
    }

    cout<<mas[n-1]<<endl;
    return 0;
}
