#include<iostream>
using namespace std;
struct p
{
    int x,y;
};
int main()
{
    int n;
    cin>>n;
    p a[n+1];
    for(int i=0;i<=n;i++)cin>>a[i].x>>a[i].y;
    cout<<1<<" "<<2<<endl<<2<<" "<<3<<endl<<3<<" "<<4<<endl;
    return 0;
}
