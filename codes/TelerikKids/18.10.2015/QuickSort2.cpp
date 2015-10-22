#include<iostream>
using namespace std;
bool a=false,b=true;
int qs[10000],qs2[10000],n,poslednocoutnato=99999,pokolkootvsekielement[1<<25],l=0;
int sortni(int na4alo,int kraj,int pivot)
{
    /*for(int i=na4alo;i<kraj;i++){
        if(a){
        cout<<qs2[i];
        }else{
        cout<<qs[i];
        }
    }
    cout<<" ";
    */
    a=!a;
    bool k=a;
    int p=na4alo;
    if(kraj-na4alo==0 or kraj-na4alo==1)
    {
        if(poslednocoutnato!=pivot and l<n)
        {
            b=false;
            poslednocoutnato=pivot;
            for(int i=0; i<pokolkootvsekielement[pivot]; i++)
            {
                cout<<pivot << " ";
                l++;
            }
                        pokolkootvsekielement[pivot]=0;
        }
        return 0;
    }
    for(int i=na4alo; i<kraj; i++)
    {
        if(a and qs[i]<pivot)
        {
            qs2[p]=qs[i];
            p++;
        }
        if(a==false and qs2[i]<pivot)
        {
            qs[p]=qs2[i];
            p++;
        }
    }
    int t=p;
    if(a)
    {
        qs2[p]=pivot;
        p++;
    }
    else
    {
        qs[p]=pivot;
        p++;
    }
    for(int i=na4alo; i<kraj; i++)
    {
        if(a and qs[i]>pivot)
        {
            qs2[p]=qs[i];
            p++;
        }
        if(a==false and qs2[i]>pivot)
        {
            qs[p]=qs2[i];
            p++;
        }
    }
    if(a)
    {
        sortni(na4alo,t,qs2[na4alo]);
        a=k;
        if(poslednocoutnato!=pivot and l<n)
        {

            b=false;
            for(int i=0; i<pokolkootvsekielement[pivot]; i++)
            {
                cout<<pivot << " ";
                l++;
            }
                        pokolkootvsekielement[pivot]=0;
            poslednocoutnato=pivot;
        }
        sortni(t+1,kraj,qs2[t+1]);
        a=k;
    }
    else
    {
        sortni(na4alo,t,qs[na4alo]);
        a=k;
        if(poslednocoutnato!=pivot and l<n)
        {
            b=false;
            for(int i=0; i<pokolkootvsekielement[pivot]; i++)
            {
                cout<<pivot << " ";
                l++;
            }
            pokolkootvsekielement[pivot]=0;
            poslednocoutnato=pivot;
        }
        sortni(t+1,kraj,qs[t+1]);
        a=k;
    }
}
int main()
{
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>qs[i];
        pokolkootvsekielement[qs[i]]++;
    }
    sortni(0,n,qs[0]);
    /*for(int i=0;i<n;i++){
        if(a){
        cout<<qs2[i];
        }else{
        cout<<qs[i];
        }
    }*/
    cout << endl;
    return 0;
}

