#include <cstdio>
#include<iostream>
#include <vector>

using namespace std;

vector<int>p[200000],cas[200000];
bool asd[200000];
bool tr,tr123;
int bez_nar(int a,int b,int n)
{

    asd[a]=1;
    if(a==b)
    {
        tr123=1;
    }
    // cout<<p[a][0];
    for(int i=0; i<p[a].size(); i++)
    {

        int k=p[a][i];
        //cout<<a<<"-->"<<k<<endl;
        if(asd[k]==0)
        {
            bez_nar(k,b,n);
        }
    }
  //  cout<<tr123<<endl;
    if(tr123==1) return 1;

}
void asdz()
{
    for(int i=0; i<200000; i++)
    {
        asd[i]=0;
    }
}
bool put(int a,int b,int n)
{
    asd[a]=1;
    if(a==b)
    {
        tr=1;
    }
    // cout<<p[a][0];
    for(int i=0; i<cas[a].size(); i++)
    {

        int k=cas[a][i];
        //cout<<a<<"-->"<<k<<endl;
        if(asd[k]==0)
        {
            put(k,b,n);
        }
    }
    if(tr==1) return 1;


}
int nbrn=1000000;
void nkrp(int a,int b,int n)
{
    asd[a]=1;
    bool tr1=0;
    for(int i=0; i<cas[a].size(); i++)
    {
        if(cas[a][i]==b)
        {
            n++;
            nbrn=n;
            tr1=1;
            break;
            asd[b]=1;
        }
    }
    if(tr1==0)
    {
        for(int i=0; i<cas[a].size(); i++)
        {
            int k=cas[a][i];
            //cout<<a<<"-->"<<k<<endl;
            if(asd[k]==0)
            {
                nkrp(k,b,n+1);
            }
        }
    }
    //return n;
}

int main()
{
    int a,b,n;
    scanf("%d%d%d",&n,&a,&b);

    int k,m;
    while(cin>>k)
    {
        cin>>m;
        p[k].push_back(m);
        cas[k].push_back(m);
        cas[m].push_back(k);
        // cout<<k<<" "<<m<<endl;
    }
    if(put(a,b,n)!=true)cout<<"X"<<endl;
    else
    {
        asdz();
        if(bez_nar(a,b,n)==1)printf("%d\n",0);
        else
        {
            asdz();
         //   cout<<"here";
            nkrp(a,b,0);
            if(nbrn%2==0)
            cout<<nbrn/2<<endl;
            else cout<<nbrn/3<<endl;


        }
    }

    return 0;
}
