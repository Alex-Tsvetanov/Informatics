#include<iostream>
#include<queue>
#include<cmath>
using namespace std;
int br=0;
int main() {
int zdr;
cin>>zdr;
int line1_y;
int line1_y_c;

queue<int> lin1;
queue<int> lin2;

for(int i=2;i>0;i++){
    line1_y_c=4+i*3;
    if(line1_y_c>zdr){

        line1_y=i+1;


        break;
    }
}
if(line1_y_c-2==zdr){
        br++;
    lin2.push(1);
    lin1.push(line1_y);
}



int maxc;

for(int i=1;i<10^6;i++){
    if((i+1)*i + (i+1)*i>zdr){
        maxc=i*2;
        break;
    }
}


if(zdr>10 and zdr<10000000){

  maxc=maxc-5;

for(int i=0;i<10;i++){

for(int x=2;x<maxc-1;x++){

    int p;
    int y=maxc-x;
    p=(x+1)*y +(y+1)*x;
    if(p -(2*(x-1)+1)==zdr){
        br++;
        lin1.push(y);
    lin2.push(x);

    }
}
maxc++;
//cout<<maxc<<endl;
}

}
if(zdr>10000000 ){

  maxc=maxc-200;

for(int i=0;i<400;i++){

for(int x=2;x<maxc-1;x++){

    int p;
    int y=maxc-x;
    p=(x+1)*y +(y+1)*x;

    if(p -(2*(x-1)+1)==zdr){
        br++;
        lin1.push(y);
        lin2.push(x);

    }
}
maxc++;
}

}

if(line1_y_c-1==zdr){
        br++;
    lin1.push(1);
    lin2.push(line1_y);
}



cout<<br<<endl;
int sz=lin1.size();
for(int i=0;i<sz;i++){
    cout<<lin2.front()<<" "<<lin1.front()<<endl;
    lin1.pop();
    lin2.pop();
}


return 0;
}
