#include<iostream>
#include<math.h>
using namespace std;
int N,M,Q;
int CalcPoints(int lP,int TP,int power[],int stX[],int stY[],int trX[],int trY[],int trR[])
{
    double dif_X;
    double dif_Y;
    double dis;
    bool wasD=false;
    for(int i=0;i<M;i++)
    {
        for(int k=0;k<Q;k++)
        {
            if(lP%2==0 && lP!=0)
            {
                wasD=true;
                power[k]=power[k]*2;
                lP=0;
            }
            else lP=0;
            for(int j=0;j<N;j++)
            {
                dis=sqrt((stX[i]-trX[j])*(stX[i]-trX[j])+(stY[i]-trY[j])*(stY[i]-trY[j]));
                if(dis+trR[j]<=power[k])
                {
                    TP+=1;
                    lP++;
                }
            }
            if(wasD)
            {
                power[k]=power[k]/2;
                wasD=false;
            }
        }
    }
    cout<<TP;
}
int main()
{
    cin>>N>>M>>Q;
    int lastPoints=0;
    int TotalPoints=0;
    int tar_X[N];
    int tar_Y[N];
    int tar_R[N];
    int stri_X[M];
    int stri_Y[M];
    int power[Q];
    for(int i=0;i<N;i++)
    {
        cin>>tar_X[i]>>tar_Y[i]>>tar_R[i];
    }
    for(int i=0;i<M;i++)
    {
        cin>>stri_X[i]>>stri_Y[i];
    }
    for(int i=0;i<Q;i++)
    {
        cin>>power[i];
    }
    CalcPoints(lastPoints,TotalPoints,power,stri_X,stri_Y,tar_X,tar_Y,tar_R);
    return 0;
}
