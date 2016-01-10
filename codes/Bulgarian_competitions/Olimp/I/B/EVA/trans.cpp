#include <iostream>
using namespace std;
int main()
{
    long int P,M,K,i=0,vazel=0;
    cin>>P>>M;
    long int a,b,c[P+1],d[P+1];
    for(i=0;i<P;i++)
	{
        c[i+1]=0;
    }
    for(i=0;i<M;i++)
	{
        cin>>a>>b;
        c[a]++;
        c[b]++;
    }
    cin>>K;
    for(i=0;i<P;i++){
        if(c[i+1]>=K){
            vazel++;
            d[i]=i+1;
            d[i+1]='\0';
        }
    }
    if(vazel>0)
        {
        cout<<vazel<<endl;
        for(i=0;i<P;i++){
            if(d[i]>0 and d[i]<P+1){
                cout<<d[i]<<" ";
            }
        }
    }

    return 0;
}
