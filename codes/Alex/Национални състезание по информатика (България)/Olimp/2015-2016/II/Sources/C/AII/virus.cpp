# include<iostream>
using namespace std;

int a[64][512];
int main()
{
    long long n;
    cin>>n;
    double p=n;
    int ans=0;
    while(p>1.0)
    {
        p/=2;
        ans++;
    }
    cout<<ans<<endl;
    if(n==1)
    {
        cout<<"1 1"<<endl;
    }
    if(n==2)
    {
        cout<<"1 1"<<endl;
    }
    if(n==3)
    {
        cout<<"2 1 2"<<endl;
        cout<<"2 1 3"<<endl;
    }
    if(n==4)
    {
        cout<<"2 1 3"<<endl;
        cout<<"2 3 2"<<endl;
    }
    if(n==5)
    {
        cout<<"2 3 5"<<endl;
        cout<<"4 1 2 3 5"<<endl;
        cout<<"3 2 4 5"<<endl;
    }
    if(n==6)
    {
        cout<<"4 1 2 3 4"<<endl;
        cout<<"3 1 2 5"<<endl;
        cout<<"4 1 3 6 5"<<endl;
    }
    if(n==7 || n==8)
    {
        cout<<"4 1 2 4 5"<<endl;
        cout<<"4 1 2 3 6"<<endl;
        cout<<"4 1 3 4 7"<<endl;
    }
    if(n==9)
    {
        cout<<"4 1 2 5 6"<<endl;
        cout<<"4 1 2 3 7"<<endl;
        cout<<"4 1 4 3 8"<<endl;
        cout<<"4 1 4 5 3"<<endl;
    }
    if(n==10)
    {
        cout<<"5 1 2 5 6 10"<<endl;
        cout<<"5 1 2 3 7 10"<<endl;
        cout<<"5 1 4 3 8 10"<<endl;
        cout<<"4 1 4 5 9"<<endl;
    }

}
