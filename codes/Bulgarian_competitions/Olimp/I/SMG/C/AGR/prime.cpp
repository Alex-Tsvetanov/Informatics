#include<iostream>
using namespace std;
int main(){
    long long prosti[3000],how=1;
    prosti[0]=2;
    string vh;
    cin>>vh;
    long long n=(vh[0]=='1'?2:0);
    for(long long i=3;how<vh.size();i++){
        bool pr=true;
        for(long long p=0;p<how && pr;p++){
            if(i%prosti[p]==0){
                  pr=false;
            }
        }
        if(pr){
            prosti[how]=i;
            if(vh[how]=='1'){
                    n+=prosti[how];
            }
            how++;
        }
    }
    cout<<n;
    return 0;
}
