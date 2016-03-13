#include<iostream>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    bool k[n][m];
    char vh;
    /*for(int x=0;x<n;x++){
        for(int y=0;y<m;y++){
            cin>>vh;
            k[x][y]=(vh=='*');
        }
    }
    bool pamet;
    for(int f=n-2;f>=0;f--){
        int move=f;
        bool fall=true;
        for(int x=f+1;x<n && fall;x++){
            for(int y=0;y<m && fall;y++){
                if(k[x][y]==true && k[f][y]==true){
                    fall=false;
                }
            }
            if(fall)   move=x;
        }
        for(int y=0;f!=move && y<m;y++){
            if(k[f][y]==true){
                k[move][y]=true;
                k[f][y]=false;
            }
        }
    }*/
    long long ans=0,poredni=0;
    for(int x=0;x<n;x++){
        bool fill=true;
        for(int y=0;y<m;y++){
            cin>>vh;
            fill=fill && vh=='*';
        }
        if(fill){
            poredni++;
        }else{
            ans+=poredni*(poredni+1)/2;
            poredni=0;
        }
    }
    ans+=poredni*(poredni+1)/2;
    cout<<ans;
}
/*
5 4
**.*
****
....
****
****
*/
/*
5 4
****
****
*.*.
.***
***.
*/
