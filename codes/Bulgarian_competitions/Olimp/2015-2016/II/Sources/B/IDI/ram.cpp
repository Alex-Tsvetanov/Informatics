#include<iostream>
#include<queue>
#include<stack>
using namespace std;
queue<int> row1;
queue<int> col1;
stack<int> row2;
stack<int> col2;
int main(){
    cin.tie(NULL);
    ios::sync_with_stdio();
    long long k;
    cin>>k;
    k*=2;
    k-=1;
    for(long long y=1;(2*y+1)*(2*y-1)<k;y++)
    {
        if(k%(2*y+1)==0)
        {
            row1.push(y);
            col1.push((k/(2*y+1)+1)/2);
        }
    }
    k-=2;
    for(long long x=1;(2*x+1)*(2*x-1)<=k;x++)
    {
        if(k%(2*x+1)==0)
        {
            col2.push(x);
            row2.push((k/(2*x+1)+1)/2);
        }
    }
    cout<<row1.size()+row2.size()<<"\n";
    while(!row1.empty())
    {
        cout<<row1.front()<<" "<<col1.front()<<"\n";
        row1.pop();
        col1.pop();
    }
    while(!row2.empty())
    {
        cout<<row2.top()<<" "<<col2.top()<<"\n";
        row2.pop();
        col2.pop();
    }
    return 0;
}
