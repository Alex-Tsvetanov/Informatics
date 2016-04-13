#include  <iostream>
#include  <cstdlib>
#include  <algorithm>
#include  <cmath>
#include  <string>
#include  <windows.h>
#include  <iomanip>
#include  <list>
using  namespace  std;
int broi1(int M, int N)
{
    int br=4+(N-1)*3+(M-1)*3+(N-1)*(M-1)*2;
    if(M<N) br=br-2*M;
    else br=br-N-(N-1);
    return br;
}
int broi(int M, int N)
{
    int br=4+(N-1)*3+(M-1)*3+(N-1)*(M-1)*2;
    int broqch=1;
    while(M>0&&N>0)
    {
        if(broqch%2==1)
        {
            N--;
            br--;
        }
        else
        {
            M--;
            br--;
        }
        broqch++;
    }
    return br;
}
int main()
{
    ios_base::sync_with_stdio(false);
    int K;
    cin>>K;
    list <int> b;
    int br=0;
    for(int i=1;i<=10000;i++)
    {
        for(int j=1;j<=10000;j++)
        {
            int a=broi1(i,j);
            if(a==K)
            {
                br++;
                b.push_back(i);
                b.push_back(j);
                //cout<<i<<" "<<j<<endl;
            }
        }
    }
    if(br==0) cout<<0;
    else cout<<br<<endl;
    while(!b.empty())
    {
        cout<<b.front()<<" ";
        b.pop_front();
        cout<<b.front()<<endl;
        b.pop_front();
    }







return 0;

}
