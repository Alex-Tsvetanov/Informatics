#include <iostream>
#include <cstdio>
using namespace std;


int asd(int a[],int b[],int curr,int ms,int summ,int ns,int maxsum,int prev,int gasf)
{
    if(gasf==1) return maxsum,curr;


    for(int i=ms; i>=0; i--)
    {
       // cout<<summ<<endl;
        if(prev!=i)
        { if((curr+b[i])>ns)  if(maxsum<summ)
        {

            return asd(a,b,curr+b[i],ms,summ+a[curr],ns,summ,i,1);
        }
        else return asd(a,b,curr+b[i],ms,summ+a[curr],ns,maxsum,i,1);



            return asd(a,b,curr+b[i],ms,summ+a[curr],ns,maxsum,i,0);
        }
    }
}int asd1(int a[],int b[],int curr,int ms,int summ,int ns,int maxsum,int prev,int gasf)
{
    if(gasf==1) return curr;


    for(int i=ms; i>=0; i--)
    {
       // cout<<summ<<endl;
        if(prev!=i)
        { if((curr+b[i])>ns)  if(maxsum<summ)
        {

            return asd(a,b,curr+b[i],ms,summ+a[curr],ns,summ,i,1);
        }
        else return asd(a,b,curr+b[i],ms,summ+a[curr],ns,maxsum,i,1);



            return asd(a,b,curr+b[i],ms,summ+a[curr],ns,maxsum,i,0);
        }
    }
}

int main()
{

    int br,n;
    int m;
    scanf("%d%d",&n,&m);
    n++;
    int ms[m],ns[n];
    for(int i=0; i<m; i++)
    {
        cin>>ms[i];
    }
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(ms[i]<ms[j])swap(ms[i],ms[j]);
        }
   }
 //   for(int i=0; i<m; i++)
   // {
     //   cout<<ms[i]<<" ";
    //}
    //cout<<endl;
    for(int i=0; i<n; i++)
    {
        cin>>ns[i];
    }

    cout<<asd(ns,ms,0,m-1,0,n,0,0,0)<<asd1(ns,ms,0,m-1,0,n,0,0,0)<<endl;




    return 0;
}
