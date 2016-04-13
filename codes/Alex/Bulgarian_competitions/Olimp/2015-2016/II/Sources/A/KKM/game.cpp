#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int main()
{
    int N; //circles
    int M; //points
    int Q; //hit power

    int x[10000], y[10000], r[10000];
    int x1[10], y1[10];

    double distances[10][10000]; //d(Om, On) + Rn
    int power[10000];
    int modifier=1, curScore=0, totalScore=0, curPower; //power modifier (if score is a matched number)
    bool flag;


    cin>>N>>M>>Q;

    for(int i=0; i<N; i++)
    {
        cin>>x[i]>>y[i]>>r[i];
    }

    for(int i=0; i<M; i++)
    {
        cin>>x1[i]>>y1[i];
    }

    for(int i=0; i<Q; i++)
    {
        cin>>power[i];
    }

    for(int i=0; i<M; i++)
    {
        for(int j=0; j<N; j++)
        {
            distances[i][j]=sqrt((x1[i]-x[j])*(x1[i]-x[j]) + (y1[i]-y[j])*(y1[i]-y[j]))+r[j];
        }
        sort(distances[i], distances[i]+N);
    }

   /*for(int i=0; i<M; i++)
    {
        for(int j=0; j<N; j++)
        {
            cout<<distances[i][j]<<" ";
        }
        cout<<endl;
    }*/

    for(int k=0; k<Q; k++)
    {
        curPower=power[k]*modifier;
        flag=true;

        for(int i=0; i<M; i++)
        {
            int j=0;
            flag=true;
            while(flag==true)
            {
                if(curPower>distances[i][j]&&distances[i][j]!=0)
                {
                    curScore+=1;
                    j++;
                }
                else
                {
                    flag=false;
                }
            }
        }
        if(curScore%2==0&&curScore!=0)modifier=2;
        else modifier=1;


        totalScore+=curScore;
        //cout<<curScore<<endl;
        curScore=0;
    }

    cout<<totalScore<<endl;

    return 0;
}
