#include<iostream>
#include<cstring>
using namespace std;
long long sum=0,numnum=0;
char number[3001];
bool g=true;
int i=2;
bool prostak(long long a){
    g=true;
    for(i=2;i<=a/2;i++){
        if(a%i==0){
            g=false;
        }
    }
    if(g==false){
        return false;
    }else{
        return true;
    }
}
int main(){
    cin>>number;
    for(int integer=2;numnum<strlen(number);integer++){
        if(prostak(integer)==true){
            sum=sum+(number[numnum]-'0')*integer;
            numnum++;
        }
    }
    cout<<sum<<endl;
return 0;
}
