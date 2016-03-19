#include<iostream>
using namespace std;
int main(){
    long long n,otg=0;
    cin>>n;
    if(n==1){
        cout<<"1\n";
        cout<<"1 1\n";
    }else
    if(n==2){
        cout<<"2\n";
        cout<<"1 1\n";
        cout<<"1 2\n";
    }else
    if(n==3){
        cout<<"2\n";
        cout<<"2 1 2\n";
        cout<<"2 1 3\n";
    }else
    if(n==4){
        cout<<"3\n";
        cout<<"2 1 2\n";
        cout<<"2 1 3\n";
        cout<<"2 1 4\n";
    }else
    if(n==5){
        cout<<"3\n";
        cout<<"3 1 2 3\n";
        cout<<"3 1 2 4\n";
        cout<<"3 1 3 5\n";
    }else
    if(n==6){
        cout<<"3\n";
        cout<<"4 1 2 3 5\n";
        cout<<"4 1 2 4 6\n";
        cout<<"3 1 3 4\n";
    }else
    if(n==7){
        cout<<"3\n";
        cout<<"4 1 2 3 5\n";
        cout<<"4 1 2 4 6\n";
        cout<<"4 1 3 4 7\n";
    }else
    if(n==8){
        cout<<"4\n";
        cout<<"4 1 2 3 5\n";
        cout<<"4 1 2 4 6\n";
        cout<<"4 1 3 4 7\n";
        cout<<"2 1 8\n";
    }else
    if(n==9){
        cout<<"4\n";
        cout<<"5 1 2 3 5 9\n";
        cout<<"4 1 2 4 6\n";
        cout<<"4 1 3 4 7\n";
        cout<<"3 1 8 9\n";
    }else
    if(n==10){
        cout<<"4\n";
        cout<<"5 1 2 3 5 9\n";
        cout<<"5 1 2 4 6 8\n";
        cout<<"4 1 3 4 7\n";
        cout<<"4 1 8 9 10\n";
    }else{
        while(n!=0){
            otg++;
            n/=2;
        }
        cout<<otg<<endl;
    }
    return 0;
}
