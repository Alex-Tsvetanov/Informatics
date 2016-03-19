#include<bits/stdc++.h>
#define MAXK 64
#define endl '\n'
using namespace std;
long long n,br,k,mas[MAXK]={0},i,pq;
vector<int>mas[MAXK];

void n_from_1_to_10(long long n)
{
    if(n==1)cout<<"1\n1 1"<<endl;
    if(n==2)cout<<"1\n1 1"<<endl;
    if(n==3)cout<<"2\n2 1 2\n2 2 3"<<endl;
    if(n==4)cout<<"3\n1 1\n1 2\n1 3"<<endl;
    if(n==5)cout<<"3\n2 3 5\n4 1 2 3 5\n3 2 4 5"<<endl;
    if(n==6)cout<<"3\n3 3 5 6\n4 1 2 3 5\n3 2 4 5"<<endl;
    if(n==7)cout<<"3\n3 3 5 6\n5 1 2 3 5 7\n4 2 4 5 7"<<endl;
    if(n==8)cout<<"4\n4 1 5 6 7\n3 2 5 8\n3 3 6 8\n2 4 7"<<endl;
    if(n==9)cout<<"4\n4 1 5 6 7\n4 2 5 8 9\n3 3 6 8\n3 4 7 9"<<endl;
    if(n==10)cout<<"4\n4 1 5 6 7\n4 2 5 8 9\n4 3 6 8 10\n4 4 7 9 10"<<endl;
}

void funk (int n)
{
    mas[0]=1;
    i=1;
    while(mas[i]<=10000000000)
    {
        mas[i]=(mas[i-1]*2);
        i++;
    }
    int z=i;
    for(i=0; i<=z; ++i)
    {
        if(n<mas[i])
        {
            cout<<i<<endl;
            pq=i;
            break;
        }
    }
}

int main()
{

    scanf("%lld",&n);
    if(n<11)
    {
        n_from_1_to_10(n);
        return 0;
    }
    if(n>500)
    {
        funk(n);
        return 0;
    }
    else
    {
        funk(n);
        return 0;
    }
}
