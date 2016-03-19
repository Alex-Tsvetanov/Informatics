#include<iostream>
#include<cmath>
#include<sstream>
#include<list>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int K = ceil(log2(n+1));
    cout<<K<<endl;
    if(n<=500)
    {
        string s[n];
        for(int i=0; i<n; i++)
        {
            int k=i+1;
            while(k!=0)
            {
                if(k%2==0) s[i]='0'+s[i];
                else s[i]='1'+s[i];
                k/=2;
            }
            int l = K-s[i].length();
            for(int h=0; h<l; h++)
            {
                s[i]='0'+s[i];
            }
        }
        list<int> A[K];
        for(int i=0; i<n; i++)
        {
            for(int k=0; k<K; k++)
            {
                if(s[i][k]=='1') A[k].push_back(i+1);
            }
        }
        for(int i=0; i<K; i++)
        {
            cout<<A[i].size();
            for(int k=0; k<A[i].size(); k++)
            {
                int t = A[i].front();
                cout<<" "<<t;
                A[i].pop_front();
                A[i].push_back(t);
            }
            cout<<endl;
        }
    }
    return 0;

}
