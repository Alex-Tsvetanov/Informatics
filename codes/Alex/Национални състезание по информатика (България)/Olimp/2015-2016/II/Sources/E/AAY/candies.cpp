#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long l,d,s,br=0;
    cin>>l>>d>>s;
    for(br=0; ;br++)
    {
        if(l==0)break;
        if(s==0)break;
        if(d==0)break;
        l=l-2;
        s=s-2;
        d=d-1;
    }


    cout<<br*2+1<<endl;
    return 0;


}


