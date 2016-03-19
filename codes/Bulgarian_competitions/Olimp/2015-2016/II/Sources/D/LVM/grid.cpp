#include<iostream>
#include<vector>
using namespace std;

struct Sq{
    bool color;
    int value=NULL;
};
struct Mn{
    int m;
    int n;
};
Sq SQ[200][200];
int maxV=1;
void GetSq(int m,int n,int maxM,int maxN)
{
    vector<Mn> MN;
    int value=maxV+1;
    if((m-1>=0)&&((SQ[m-1][n].color)&&(SQ[m-1][n].value==NULL)))
    {
        Mn MNN;
        MNN.m=m-1;
        MNN.n=n;
        MN.push_back(MNN);
    }
    else
    {
        if((SQ[m-1][n].value!=NULL)&&(m-1>=0))
        {
        value=SQ[m-1][n].value;
        //cout<<SQ[m-1][n].value;
        }
    }





     if((n-1>=0)&&((SQ[m][n-1].color)&&(SQ[m][n-1].value==NULL)))
    {
        Mn MNN;
        MNN.m=m;
        MNN.n=n-1;
        MN.push_back(MNN);
    }
    else
    {
        if((SQ[m][n-1].value!=NULL)&&(n-1>=0))
        {
        value=SQ[m][n-1].value;
        }
    }




         if((n+1<=maxN)&&((SQ[m][n+1].color)&&(SQ[m][n+1].value==NULL)))
    {
        Mn MNN;
        MNN.m=m;
        MNN.n=n+1;
        MN.push_back(MNN);
    }
    else
    {
        if((SQ[m][n+1].value!=NULL)&&(n+1<=maxN))
        {
        value=SQ[m][n+1].value;
        }
    }





     if((m+1<=maxM)&&((SQ[m+1][n].color)&&(SQ[m+1][n].value==NULL)))
    {
        Mn MNN;
        MNN.m=m+1;
        MNN.n=n;
        MN.push_back(MNN);
    }
    else
    {
        if((SQ[m+1][n].value!=NULL)&&(m+1<=maxM))
        {
        value=SQ[m+1][n].value;
        }
    }

    SQ[m][n].value=value;
   // cout<<value<<endl;
    if(value==maxV+1)maxV++;
    for(int br=0;br<MN.size();br++)
    {
        GetSq(MN[br].m,MN[br].n,maxM,maxN);
    }
}
int main()
{
    int m,n;
    cin>>m>>n;
    for(int br=0;br<m;br++)
    {
        for(int brr=0;brr<n;brr++)
        {
            cin>>SQ[br][brr].color;
            SQ[br][brr].color =!SQ[br][brr].color;
        }
    }
    SQ[0][0].value=1;
      for(int br=0;br<m;br++)
    {
        for(int brr=0;brr<n;brr++)
        {
            if((SQ[br][brr].color)&&(SQ[br][brr].value==NULL));
            {
               GetSq(br,brr,m-1,n-1);
            }
        }

    }
    cout<<maxV<<endl;
    return 0;
}
