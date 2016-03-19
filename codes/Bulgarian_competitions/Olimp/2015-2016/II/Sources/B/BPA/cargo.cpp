#include <iostream>

using namespace std;



string o = "OK";
string m = "MIXED";
string imp = "IMPOSSIBLE";

int main(){

int N, M, P;
cin>>N>>M>>P;

int team = P/2;

bool flights[M][team];



int S[M];
int E[M];


for(int i = 0; i<M; i++){
    cin>>S[i]>>E[i];
    for(int ii = 0; ii<team; ii++){
        flights[i][ii] = false;
    }
}

int overall = 0;



for(int i = 0; i<M; i++){
    bool successful = false;
    for(int z = S[i]; z<E[i]; z++){
        for(int x = 0; x<team; x++){

        if(!flights[z][x] && z % 7 != 6 && z % 7 != 7 && !successful){
            flights[z][x] = true;
            successful = true;
            //cout<<"first"<<endl;
        }
        //cout<<"is working at: "<<i <<" and " <<x << " with " << team << " teams and is successful: " << successful <<
            //"and the flight is empty: " << flights[z][x]<<endl ;
        }
    }
    if(successful){
        //cout<<"tell";
        if(overall != 0){
            //cout<<i<<endl;
        }
    }else{
        for(int z = S[i]; z<E[i]; z++){
        for(int x = 0; x<team; x++){
        if(!flights[z][x] && !successful){
            flights[z][x] = true;
            successful = true;
            //cout<<"second"<<endl;
        }
        }
    }
    if(successful){

        if(overall == 0){
            overall = 1;
        }
    }else{

        overall = 2;
            }
    }



}
switch(overall){
case 0:
    cout<<o;
    break;
case 1:
    cout<<m;
break;
case 2:
    cout<<imp;
break;
}


oout<<endl;


return 0;
}
