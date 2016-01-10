#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int otkade[100000],dokade[100000],gradove[100000],izhod[100000];
    int p,m,k,s;
    int i=0;
    int mini,swup,minipos;
    cin>>p>>m;
    for(int br=0; br<m; br++)
    {
        cin>>otkade[br]>>dokade[br];
    }
    cin>>k;
    for(int br=0; br<=m; br++)
    {
        gradove[otkade[br]]++;
        gradove[dokade[br]]++;
    }
    for(int br=1; br<=m; br++)
    {
        if(gradove[br]>=k)
        {
            izhod[i]=br;
            i++;
        }
    }
    mini=izhod[0];
    for(int y=0; y<i; y++)
    {
        for(s=y; s<i; s++)
        {
            if(izhod[s]<mini)
            {
                mini=izhod[s];
                minipos=s;
            }
        }
        if(s<i){
        swup=izhod[y];
        izhod[y]=mini;
        izhod[minipos]=swup;
        mini=izhod[y+1];
    }
    }

    for(int br=0; br<i; br++)
    {
        cout<<izhod[br]<<" ";
    }
    cout<<endl;
    return 0;
}
