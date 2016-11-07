#include<iostream>
using namespace std;
int main ()
{
    int n,j=2;
    cin>>n;
    if(n==2) cout<<1<<endl<<1;//ako se ocveti znachi 1 e s virus,
    //ako ne se ocveti znachi 2 e svirus
    else {cout<<3<<endl;
    for(int i=1;i<=3;i++)
    {
        j++;
            cout<<"1"<<n-j<<n-i<<n<<endl;

    }}
    return 0;
}
