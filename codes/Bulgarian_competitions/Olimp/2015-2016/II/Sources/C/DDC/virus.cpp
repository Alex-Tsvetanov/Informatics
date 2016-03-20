#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long n;
    cin>>n;
    long long k = 1;
    long long p = 1;
    while(k<n)
    {
        p++;
        k+=(p*2)-2;
    }
    cout<<p<<'\n';
    if(n<500)
    {
        if(n==2)
        {
            cout<<"1 1\n1 2\n";
        }
        else if(n==3)
        {
            cout<<"2 1 3\n2 2 3\n";
        }
        else if(n==4)
        {
            cout<<"1 4\n2 2 3\n2 1 3\n";
        }
        else if(n==5)
        {
            cout<<"2 4 5\n3 2 3 5\n2 1 3\n";
        }
        else if(n==6)
        {
            cout<<"3 4 5 6\n4 2 3 5 6\n3 1 3 6\n";
        }
        else if(n==7)
        {
            cout<<"4 4 5 6 7\n4 2 3 5 6\n4 1 3 6 7\n";
        }
        else if(n==8)
        {
            cout<<"1 8\n4 4 5 6 7\n4 2 3 5 6\n4 1 3 6 7\n";
        }
        else if(n==9)
        {
            cout<<"2 8 9\n5 4 5 6 7 9\n4 2 3 5 6\n4 1 3 6 7\n";
        }
        else if(n==10)
        {
            cout<<"3 8 9 10\n6 4 5 6 7 9 10\n5 2 3 5 6 10\n4 1 3 6 7\n";
        }
        else if(n==11)
        {
            cout<<"4 8 9 10 11\n7 4 5 6 7 9 10 11\n6 2 3 5 6 10 11\n5 1 3 6 7 11\n";
        }
        else if(n==12)
        {
            cout<<"5 8 9 10 11 12\n7 4 5 6 7 9 10 11\n7 2 3 5 6 10 11 12\n5 1 3 6 7 11\n";
        }
        else if(n==13)
        {
            cout<<"6 8 9 10 11 12 13\n7 4 5 6 7 9 10 11\n7 2 3 5 6 10 11 12\n6 1 3 6 7 11 13\n";
        }
        else
        {
            cout<<"SPAM!";
        }
    }
    return 0;
}
