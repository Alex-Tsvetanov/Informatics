#include<iostream>
#include<algorithm>
#include<cmath>
#include<string>
using namespace std;
bool cmp(pair<int,int> x,pair<int,int> y)
{
    if(x.first<y.first)return true;
    if(x.second<y.second)return true;
    return false;
}
/*int fakt(int a)
{
    int fa=1;
    for(int i=1;i<=a;i++)
        fa=fa*i;
    return fa;
}*/
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,p;
    pair<int,int> v[1000002];
    cin>>n>>m>>p;
  /*  Ako se ima predvid v uslovieto,
    che 1 pilot moje da pravi po poveche ot 1 kurs na den ako e v razlichen ekipaj, to:*/
  /*  p=fakt(p)/fakt(p-2)*/
    p=p/2;
    for(int i=1;i<=m;i++)
    {
        cin>>v[i].first>>v[i].second;
    }
    sort(v+1,v+m+1,cmp);
    int d=v[1].first,brzd=p;
    string ans="OK";
    for(int i=1;i<=m;i++)
    {
        if(v[i].first<=d and v[i].second>=d)
        {
            if(brzd>0)brzd--;
            else
            {
                brzd=p;
                if(d%7==5)d+=3;
                else d++;
                brzd--;
                if(v[i].second<d or d>n){ans="MIXED";break;}

            }
        }

        else
            {
                d=v[i].first;
                brzd=p-1;
                if(d%7==6)d+=2;
                if(d%7==0)d+=1;
                if(v[i].second<d or d>n){ans="MIXED";break;}
            }
    }
    if(ans=="MIXED")
    {
        brzd=p;d=v[1].first;
       for(int i=1;i<=m;i++)
    {
        if(v[i].first<=d and v[i].second>=d)
        {
            if(brzd>0)brzd--;
            else
            {
                brzd=p;

                 d++;
                brzd--;
                if(v[i].second<d or d>n){ans="IMPOSSIBLE";break;}

            }
        }

        else
            {
                d=v[i].first;
                brzd=p-1;

                if(v[i].second<d or d>n){ans="IMPOSSIBLE";break;}
            }
    }
    }
    cout<<ans<<endl;
    return 0;
}
