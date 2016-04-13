#include<iostream>
using namespace std;
int main(){
int n, delitel=1, minRaz=100000, delitelPredi;
cin>>n;
while(delitel<=n/2){
    if(n%delitel==0){
        if(minRaz>n/delitel-delitel<minRaz){
            minRaz=n/delitel-delitel;
            delitelPredi=delitel;
        }
    }
    delitel++;
}
cout<<delitelPredi<<n/delitelPredi<<endl;
cout<<2*(delitelPredi+n/delitelPredi)<<endl;
return 0;
}
