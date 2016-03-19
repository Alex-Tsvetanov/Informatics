#include<iostream>
using namespace std;
int n,s,p,br;
void var(int i,int sum)
{
    int j;
    for(j=0;j<p;j++)
    {
        sum+=j;
        if(i==n-1)
        {
            if(sum<s) br++;
        }
        else
            var(i+1,sum);
    }
}
int main()
{
     cin>>p>>n>>s;
      var(0,0);
      cout<<br<<endl;
}
