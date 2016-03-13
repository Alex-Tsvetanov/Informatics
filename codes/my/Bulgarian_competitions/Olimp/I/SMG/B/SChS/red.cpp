#include<iostream>
using namespace std;
int main(){
unsigned int n,mini,maxi,redica[100000];
cin>>n;
unsigned int minmqsto=0,maxmqsto=n-1;
for(int br=0;br<n;br++){
    cin>>redica[br];
}
mini=redica[0];
maxi=redica[0];
for(int br=1;br<n;br++){
    if(mini>redica[br]){
        mini=redica[br];
        minmqsto=br;
    }
}
for(int br=n;br>1;br=br-1){
    if(maxi<redica[br]){
        maxi=redica[br];
        maxmqsto=br;
    }
}
minmqsto++;
maxmqsto++;
if(maxmqsto>minmqsto){
    cout<<minmqsto<<" "<<maxmqsto<<endl;
}
else{
    cout<<maxmqsto<<" "<<minmqsto<<endl;
}
return 0;
}
