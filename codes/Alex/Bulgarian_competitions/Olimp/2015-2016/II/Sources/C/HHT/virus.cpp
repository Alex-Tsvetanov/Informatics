#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    long long n,n1,k,i;
    cin>>n;
    n1=n;
    for(i=0;n1>=1;i++){
        n1=n1/2;
    }
    k=i;
    cout<<k<<"\n";
    if(n==2){
        cout<<"1 1\n1 2";
        cout<<endl;
    }
    if(n==3){
        cout<<"2 1 3\n2 2 3";
        cout<<endl;
    }
    if(n==4){
        cout<<"2 1 4\n2 2 4\n1 3";
        cout<<endl;
    }
    if(n==5){
        cout<<"2 3 5\n4 1 2 3 5\n3 2 4 5";
        cout<<endl;
    }
    if(n==6){
        cout<<"3 1 3 4\n3 1 2 5\n3 2 3 6";
        cout<<endl;
    }
    if(n==7){
        cout<<"4 1 3 4 7\n4 1 2 5 7\n4 2 3 6 7";
        cout<<endl;
    }
    if(n==8){
        cout<<"4 1 4 5 8\n4 1 2 6 8\n5 2 3 4 7 8\n5 3 5 6 7 8";
        cout<<endl;
    }
    if(n==9){
        cout<<"5 1 4 5 8 9\n5 1 2 6 8 9\n6 2 3 4 7 8 9\n5 3 5 6 7 8";
        cout<<endl;
    }
    if(n==10){
        cout<<"6 1 4 5 8 9 10\n6 1 2 6 8 9 10\n6 2 3 4 7 8 9\n6 3 5 6 7 8 10";
        cout<<endl;
    }
return 0;
}
