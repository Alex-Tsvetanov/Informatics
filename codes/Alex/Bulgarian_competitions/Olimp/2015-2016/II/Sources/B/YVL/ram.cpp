#include<vector>
#include<iostream>
using namespace std;
int main(){
    int k;
    cin>>k;
    int redove;
    double koloni;
    vector<int> res;
    for(int redove=1;redove<k/3+2;redove++){
        double f=1.0*(k-redove-1)/(1+2*redove-2);
        double s=1.0*(k+redove)/(1+2*redove);
        if(redove>=f && ((k-redove-1)%(1+2*redove-2))==0){
            res.push_back(redove);
            res.push_back(f);
        }
        if(redove<s && ((k+redove)%(1+2*redove))==0){
            res.push_back(redove);
            res.push_back(s);
        }
    }
    cout<<res.size()/2<<"\n";
    for(int i=0;i<res.size();i+=2){
        cout<<res[i]<<" "<<res[i+1]<<"\n";
    }
    return 0;
}
