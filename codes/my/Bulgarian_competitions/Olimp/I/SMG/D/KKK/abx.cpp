#include<iostream>
using namespace std;
int main()
{
    string e;
    int c=0,d=0;
    cin>>e;
    int ukaz=0;
    int n=e.size();
    for(int i=0;i<n;i++){
        if(e[i]<='9' and e[i]>='0'){
            if(ukaz==0 or ukaz==1){
                c=c*10+e[i]-'0';
            }else if(ukaz==2){
                d=d*10+e[i]-'0';
            }
        }
        if(e[i]=='+'){
            ukaz++;
        }
        if(e[i]=='='){
            ukaz=2;
        }
    }
    cout<<d-c<<endl;
    return 0;
}
