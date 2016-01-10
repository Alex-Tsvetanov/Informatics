#include<iostream>
using namespace std;
int vhod[1000003];
int main(){
    int n,maxN=2147483647,minN=-2147483647;
    cin>>n;
    for(int br1=0;br1<n;br1++){
        cin>>vhod[br1];
        if(maxN>vhod[br1]){
            maxN=vhod[br1];
        }
        if(minN<vhod[br1]){
            minN=vhod[br1];
        }
    }
    int ans1,ans2,ans3,ans4;
    bool foundFirstMax=0,foundFirstMin=0;
    for(int br1=0;br1<n;br1++){
        if(maxN==vhod[br1] && !foundFirstMax){
            ans1=br1;
            foundFirstMax=1;
        }
        if(minN==vhod[br1] && !foundFirstMin){
            ans2=br1;
            foundFirstMin=1;
        }
        if(foundFirstMax && foundFirstMin){
            break;
        }
    }



    bool foundLastMax=0,foundLastMin=0;
    for(int br1=n-1;br1>=0;br1--){
        if(maxN==vhod[br1] && !foundLastMax){
            ans3=br1;
            foundLastMax=1;
        }
        if(minN==vhod[br1] && !foundLastMin){
            ans4=br1;
            foundLastMin=1;
        }
        if(foundLastMax && foundLastMin){
            break;
        }
    }
    if(ans4-ans1>=ans3-ans2){
        cout<<ans1+1<<" "<<ans4+1;
    }
    if(ans4-ans1<ans3-ans2){
        cout<<ans2+1<<" "<<ans3+1;
    }
    cout<<endl;
    return 0;
}
