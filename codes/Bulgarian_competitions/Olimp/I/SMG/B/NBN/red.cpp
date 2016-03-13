#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int red[20001];
    for(int i = 0;i < n;i++)
        cin>>red[i];
    //int rec[20000];
    int tempFirst,tempLast,first,last,dulj=-1,tempDulj;
    int maxSbTemp;
    int maxSb = -1;
    int tempVal;
    for(int i = 1;i < n;i++)
    {
        maxSbTemp = -1;
        for(int j = 0;j < i;j++)
        {
            tempVal = abs(red[j]-red[i]);
            if(tempVal > maxSbTemp)
            {
                tempFirst = j;
                tempLast = i;
                maxSbTemp = tempVal;
                tempDulj = i-j+1;
            }
        }
        if(maxSbTemp >= maxSb && tempDulj>dulj)
        {
            first = tempFirst;
            last = tempLast;
            maxSb = maxSbTemp;
            dulj=tempDulj;
        }
    }
    cout<<first+1<<" "<<last+1<<endl;
    return 0;
}
