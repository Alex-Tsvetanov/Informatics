#include <iostream>
#include <cstring>
using namespace std;

char a[10001];
int p[10000], n;

void inp()
{
    cin>>a;
}

bool isPal(char *a, int n)
{
    if (n==1 || n==0) return true;
    int k = n/2;
    
    for (int i=0;i<k;i++) if (a[i]!=a[n-i-1]) return false;
    return true;
}

void init(int *a, int n)
{
    for (int i=0;i<n;i++) a[i] = i;
}

void nextItt(int s, int s1)
{
    if (p[1]<=n-s1)
    {
        p[s]++;
        if (p[s]>n-1-(s1-s-1))
        {
            nextItt(s-1, s1);
            if (s>0) p[s] = p[s-1]+1;
        }
    }
}

template <class T>
void show(T *a, int n)
{
    for (int i=0;i<n;i++) cout<<a[i]<<' ';
    cout<<endl;
}

bool itt(int s)
{
    init(p, s);
    p[s] = n;
    while(p[1]<=n-s)
    {
        bool t = true;
        for (int i=1;i<=s;i++) 
        {
            if (!isPal(&a[p[i-1]], p[i]-p[i-1])) t = false;
            //show(&a[p[i-1]], p[i]-p[i-1]);
        }
        if (t == true) return true;
        //cout<<endl<<endl;;
        nextItt(s-1, s);
    }
    
    return false;
}

void sol()
{
    for (int i=2;true;i++)
    {
        if (itt(i)) 
        {
            cout<<i-1<<endl;
            return;
        }
    }
}

int main()
{
    inp();
    n = strlen(a);
    if (isPal(a, n)) 
    {
        cout<<0<<endl;
        return 0;
    }
    sol();
    return 0;
}