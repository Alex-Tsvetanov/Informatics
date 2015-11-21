#include<iostream>
#include<algorithm>

using namespace std;


int s(string a,string b)
{
    string res=a;
    int n=0;
    for(int i=a.size()-1;i>=0;i--)
    {
        res[i]=(a[i]+b[i]);
        if(res[i]>'9')
        {
            res[i]-=9;
            n++;
        }
    }

    return res;
}

int main()
{

    string b,a,c;
    cin>>b;
    sort(b.begin(),b.end());
    a=b;
    for(int i=0;i<b.size()/2;i++)
    {
        swap(b[i],b[b.size()-i-1]);
    }
    c=b;



    return 0;
}
