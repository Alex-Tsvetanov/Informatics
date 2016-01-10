#include<iostream>
#include<cstring>
using namespace std;
long long p[3001];
char a[3001];
bool is_simple(int number){
    if(number==2){
        return true;
    }
    if(number==3){
        return true;
    }
    if(number==5){
        return true;
    }
    if(number==7){
        return true;
    }
    if(number%2!=0 && number%3!=0 && number%5!=0 && number%7!=0){
        return true;
    }
    return false;

}
int main(){
    long long found=0,score=0;
    for(int i=0;i<3001;i++){
        if(is_simple(i+2)){
            p[found] = i+2;
            found = found + 1;
        }
    }
    cin>>a;
    for(int i=0;i<strlen(a);i++){
        score = score + (int(a[i])-48)*p[i];
    }
    cout<<score<<endl;


    return 0;
}
