#include<iostream>
#include<cmath>
using namespace std;
int n, chisla[20002];
int indMax1, indMax2,indMin1, indMin2;
int maxx=-1,minn=2000008;
int main(){
cin>>n;
for(int i=0;i<n;i++)
{
    cin>>chisla[i];
    if(chisla[i]<=minn)
    {
        if(chisla[i]<minn)
        {
            indMin1=i;
        }
        else
        {
            indMin2=i;
        }
        minn=chisla[i];
    }
     if(chisla[i]>=maxx)
    {
        if(chisla[i]>maxx)
        {
            indMax1=i;
        }
        else
        {
            indMax2=i;
        }
        maxx=chisla[i];
    }

}
///cout<<indMin1<<" "<<indMin2<<" "<<indMax1<<" "<<indMax2<<endl;
if(abs(indMin1-indMax2)>abs(indMin2-indMax1))
{
    cout<<min(indMin1+1,indMax2+1)<<" "<<max(indMin1+1,indMax2+1)<<endl;
}
else
{
    if(abs(indMin1-indMax2)==abs(indMin2-indMax1))
    {
        if(indMin1+indMax2<indMin2+indMax1)
            cout<<min(indMin1+1,indMax2+1)<<" "<<max(indMin1+1,indMax2+1)<<endl;
        else
            cout<<min(indMin2+1,indMax1+1)<<" "<<max(indMin2+1,indMax1+1)<<endl;
    }
    else
    cout<<min(indMin2+1,indMax1+1)<<" "<<max(indMin2+1,indMax1+1)<<endl;
}
/// TESTVAJ MNOOOGO!!!

return 0;
}
