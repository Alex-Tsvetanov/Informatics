#include<iostream>

using namespace std;
int arr[20016];
int main()
{
    int N;
    cin>>N;
    int vmin=1000001,vmax=-1;
    int rmin,rmax;
    int rmin2,rmax2;

    for(int i=1;i<=N;i++)
    {
        cin>>arr[i];
        if(arr[i]<vmin){vmin=arr[i];rmin=i;}
        if(arr[i]>=vmax){vmax=arr[i];rmax=i;}
    }
    vmin=1000001;vmax=-1;
    for(int i=N;i>=1;i--)
    {
        if(arr[i]<vmin){vmin=arr[i];rmin2=i;}
        if(arr[i]>=vmax){vmax=arr[i];rmax2=i;}
    }
    if(vmin==vmax){cout<<1<<" "<<N<<endl;return 0;}
    //cout<<rmin<<" "<<rmax<<"\n"<<rmax2<<" "<<rmin2;
    if(rmax-rmin>rmin2-rmax2){cout<<rmin<<" "<<rmax<<endl;return 0;}
    if(rmax-rmin<rmin2-rmax2){cout<<rmax2<<" "<<rmin2<<endl;return 0;}
    if(rmax+rmin<rmax2+rmin2){cout<<rmin<<" "<<rmax<<endl;return 0;}
    cout<<rmax2<<" "<<rmin2<<endl;
    return 0;
}
