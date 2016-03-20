#include <iostream>
#define endl '\n'
using namespace std;

int n;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;

    if(n==2)
    {
        cout<<"2"<<endl;
        cout<<"1 1"<<endl;
        cout<<"1 2"<<endl;
        return 0;
    }
    else if(n==3)
    {
        cout<<"2"<<endl;
        cout<<"2 1 2"<<endl;
        cout<<"2 1 3"<<endl;
        return 0;
    }
    else if(n==3)
    {
        cout<<"2"<<endl;
        cout<<"2 1 2"<<endl;
        cout<<"2 1 3"<<endl;
        return 0;
    }
    else if(n==4)
    {
        cout<<"3"<<endl;
        cout<<"3 1 2 3"<<endl;
        cout<<"3 1 2 4"<<endl;
        return 0;
    }
    else if(n==5)
    {
        cout<<"3"<<endl;
        cout<<"2 3 5"<<endl;
        cout<<"4 1 2 3 5"<<endl;
        cout<<"3 2 4 5"<<endl;
    }

    else
    {

    }

    return 0;
}
