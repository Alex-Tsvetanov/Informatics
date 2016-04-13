#include<iostream>
#include<algorithm>
using namespace std;
bool cmp(pair<long long,char> a,pair<long long,char> b)
{
    if(b.first==a.first){
        return b.second>a.second;
    }else{
        return b.first<a.first;
    }
}
pair<long long,char> bukvi[26];
int main()
{
    char a;
    cin>>a;
    while(a!='#')
    {
        if(a-'A'<=25 and a-'A'>=0)
        {
            a=a-'A'+'a';
        }
        if(a-'a'<=25 and a-'a'>=0)
        {
            bukvi[a-'a'].first++;
            bukvi[a-'a'].second=a;
        }
        cin>>a;
    }
    sort(bukvi,bukvi+26,cmp);
    for(long long i=0; i<6; i++)
    {
        if(bukvi[i].first==0)
        {
            break;
        }
        else
        {
            cout<<(char)(bukvi[i].second-'a'+'A');
        }
    }
    cout<<endl;
    return 0;
}
