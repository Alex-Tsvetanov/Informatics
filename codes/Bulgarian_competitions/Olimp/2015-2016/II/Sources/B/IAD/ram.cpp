#include <iostream>
#include <queue>
using namespace std;
void tr(int k, int until)
{
    queue<int> ms;
    for(int m = 1; m < until; m ++)
    {
        int n1 = (k-m-1)/(2*m-1), n2 = (k+m)/(2*m+1);
        if(n1 > 0 && m>=n1 && (k-m-1)%(2*m-1) == 0 && m*(n1+1)+n1*(m+1)-2*n1+1 == k) ms.push(m);
        if(n2 > 0 && m < n2 && (k+m)%(2*m+1) == 0 && m*(n2+1)+n2*(m+1)-2*m == k) ms.push(m);
    }
    cout << ms.size() << endl;
    int ans = ms.size();
    for(int i = 0; i < ans; i ++)
    {
        int m = ms.front();
        cout << m << " ";
        int n1 = (k-m-1)/(2*m-1), n2 = (k+m)/(2*m+1);
        if(m>=n1 && m*(n1+1)+n1*(m+1)-2*n1+1 == k && (k-m-1)%(2*m-1) == 0) cout << (k-m-1)/(2*m-1) << endl;
        if(m < n2 && m*(n2+1)+n2*(m+1)-2*m == k && (k+m)%(2*m+1) == 0) cout << (k+m)/(2*m+1) << endl;
        ms.pop();
    }
}
int main()
{
    ios::sync_with_stdio(false);
    int k = 0;
    cin >> k;
    if(k <= 20000000) tr(k, k);
    else tr(k, 20000000);
}
