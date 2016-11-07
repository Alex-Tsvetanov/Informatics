#include<iostream>
#include<stack>
#define MAXN 1000002
using namespace std;
int n, maxp;
int a[MAXN];
stack <int> st;
void Init ()
{
    cin>>n;
    for (int i=0; i<n; i++)
        cin>>a[i];
    st.push (a[n-1]);
    maxp=a[n-1];
}
void Solve ()
{
    for (int i=n-2; i>=0; i--)
    {
        if (a[i]<maxp) continue;
        st.push (a[i]);
        maxp=a[i];
    }
}
void Print ()
{
    bool l=false;
    while (st.size ()!=0)
    {
        if (l==true) cout<<' ';
        l=true;
        cout<<st.top ();
        st.pop ();
    }
    cout<<endl;
}
int main ()
{
    Init ();
    Solve ();
    Print ();
    return 0;
}
