#include<iostream>
#include<stack>
#include<vector>
#include<map>
using namespace std;
map<int,pair<bool,int> >value;
bool v[26];
vector<pair<int,int> >val[1024];
int n;
int mx=0;
string ans="";
string s;
stack<pair<int,int> >br;
int pri=1;
bool func(bool a,bool b)
{
    if( a&&b)return 0;
    return 1;
}
void computer()
{
    for(int i=mx;i>=0;i--)
    {
        for(int j=0;j<val[i].size();j++)
        {
            int strt=val[i][j].first;
            int endi=val[i][j].second;
            bool values,bad=1;
           // if(!(s[strt+1]>='a' && s[strt+1]<='z'))bad=1;
            //else values=v[s[strt+1]-'a'];
            //int fr=2;
            //if(bad)fr=1;
            for(int o=strt+1;o<endi;o++)
            {
                bool crrv;
                if(s[o]=='(')
                   {
                       crrv=value[o].first;
                        if(!bad)values=func(values,crrv);
                        else values=crrv,bad=0;
                       o=value[o].second;
                       continue;
                   }
                if(s[o]!=')'){
                    crrv=v[s[o]-'a'];
                if(!bad)values=func(values,crrv);
                else values=crrv;}
            }
            value[strt]={values,endi};
        }
    }
    //cout<<value[-1].first<<endl;
    bool endv;
    bool sh=1;
    for(int i=0;i<n;i++)
    {
        bool crv;
        if(s[i]=='(')
           {
               crv=value[i].first;
               if(!sh)endv=func(endv,crv);
               else endv=crv,sh=0;
               i=value[i].second;
               continue;
           }
           crv=v[s[i]-'a'];
        if(!sh)endv=func(endv,crv);
        else endv=crv,sh=0;
    }
    //cout<<endv<<endl;
    if(endv==0)ans+='0';
    else ans+='1';
}
int main()
{


    cin>>s;
    n=s.size();
   /* for(int i=0;i<n;i++)
    {
        if(s[i]>='a' && s[i]<='z')cntl[s[i]-'a']++;
    }*/


    for(int i=0;i<n;i++)
    {
        if(s[i]=='(')
           {
               br.push({i,pri});
               pri++;
           }
        else if(s[i]==')')
        {
            pair<int,int> crr;
            crr=br.top();
            br.pop();
            mx=max(mx,crr.second);
            val[crr.second].push_back({crr.first,i});
            pri--;
        }
    }
    //val[0].push_back(-1,n);
    while(1)
    {
        string shite;
        cin>>shite;
        if(shite=="2")break;
        for(int i=0;i<shite.size();i++)
        {
            bool hah;
            if(shite[i]=='0')hah=0;
            else hah=1;
            v[i]=hah;
        }
        computer();
    }
    cout<<ans<<endl;
    return 0;
}
