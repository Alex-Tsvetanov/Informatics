#include <iostream>
using namespace std;
long long red[1000005],lead[1000005],n,i,j,k=0;
bool fl=true;
int main()
{
    cin>>n;
    for ( i=0 ; i<n ; i++ )
    {
        cin>>red[i];
    }
    for ( i=0 ; i<n ; i++ )
    {
        fl=true;
        for ( j=i+1 ; j<n ; j++ ){/**cout<<red[i] <<" "<< red[j]<<endl;*/if(red[j]>red[i]){fl=false;/**cout<<"greshka"<<endl;*/break;}}
        if(fl==true){lead[k]=red[i];k++;}
    }
    for ( i=0 ; i<k ; i++ )
    {
        if( i==k-1 )cout<<lead[i]<<endl;
        else cout<<lead[i]<<" ";
    }
	return 0;
}
