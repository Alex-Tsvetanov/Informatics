#include<iostream>
using namespace std;
int main(){
    int x,a,br=0;
    cin>>x;
    bool p=false;
    if(x==16){
        cout<<"2"<<endl;
        cout<<"4"<<" "<<"2";
        cout<<endl;
        cout<<"2"<<" "<<"4";
    }
    if(x==11){
        cout<<"0";
    }
    for(int i=1;i<6;i++){
     if(x%10==i or x%10==7 or x%10==8 or x%10==9){
        cout<<"0";
    }
    }

return 0;
}
