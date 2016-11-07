#include <iostream>
#include <cstring>
using namespace std;

char a[1024];
char b[200003][30];
int g[30];

template <class T>
void show(T *a, int n)
{
    for (int i=0;i<n;i++) cout<<a[i]<<' ';
    cout<<endl;
}

void inp()
{
    cin>>a;
    for (int i=0;true;i++)
    {
        cin>>b[i];
        if (b[i][0] == '2') return;
    }
}

void rend(char *a)
{
    for (int i=0;i<30;i++) g[i] = -1;
    for (int i=0;a[i]!=0;i++) if(a[i]!='(' && a[i]!=')') g[a[i]-'a'] = a[i]-'a';
    int c = 0;
    for (int i=0;i<30;i++)
    {
        if (g[i]==-1) c++;
        else g[i]-=c;
    }
    //show(g, 27);
}

char cl(char a, char b)
{
    if (a=='1' && b=='1') return '0';
    if (a == 0) return b;
    if (b == 0) return a;
    return '1';
}

char calc(char *a)
{
    char r[1024];
    memset(r, 0, 1000*sizeof(char));
    int p=0;
    for (int i=0;a[i]!=0;i++)
    {
        if (a[i]=='(') p++;
        else if (a[i]==')') 
        {
            p--;
            r[p] = cl(r[p], r[p+1]);
            r[p+1] = 0;
        }
        else r[p] = cl(a[i], r[p]);
    }
    return r[0];
}

void sol()
{
    char t[1024];
    
    for (int i=0;true;i++)
    {
        if (b[i][0] == '2') 
        {
            cout<<endl;
            return;
        }
        
        int j=0;
        for (;a[j]!=0;j++)
        {
            if (a[j] == '(' || a[j] == ')') t[j] = a[j];
            else t[j] = b[i][g[a[j]-'a']];
        }
        t[j] = 0;
        
        cout<<calc(t);
    }
}

int main()
{
    inp();
    rend(a);
    sol();
    return 0;
}


/*
a(a)(ab(da)bb)d
011
100
010
111
001
2
*/