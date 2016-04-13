#include<iostream>
#include<vector>
using namespace std;

int main (){
    int p,n,s;
    long long broi=1;
    long long sum=0;
    int p1=1;
    int n1=2;
    vector<int> chisl;
    cin>>p>>n>>s;
    for(int i=0;i<n;i++){
        chisl.push_back(0);
    }
    long long ms=0;
    while(p1<p){
        n1=1;
        while(n1<=n){
            if(n1*p1<s){
                if(n1==1){
                    broi+=n;
                }else{
                    broi+=n/(n1-1);
                }
            }
            n1++;
        }
        p1++;
    }


cout<<broi<<endl;
return 0;
}

