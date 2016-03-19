#include<iostream>
using namespace std;

int main(){

long long a, b, c, i=0, br=0;

cin>>a>>b>>c;


while(i<1){
        if(a==0) break;
        a--;
        br++;
        if(b==0) break;
        b--;
        br++;
        if(c==0) break;
        c--;
        br++;
        if(b==0) break;
        b--;
        br++;
}
cout<<br;
}
