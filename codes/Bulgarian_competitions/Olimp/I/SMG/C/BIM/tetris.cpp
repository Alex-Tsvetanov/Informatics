#include<iostream>

using namespace std;

int main (){
    int points=0;
    int psl=0;
    int n,m;
    cin>>n>>m;
    string str[n];
    bool yes=true;
    bool yes1=true;
    for(int j=0;j<n;j++){
        cin>>str[j];
        for(int i=0;i<m;i++){
            if(str[j][i]=='.'){
                yes=false;
                break;
            }

        }
        if(yes==true){
            psl++;
        }
        if(yes==false){
            points=points+(psl*(psl+1)/2);
            psl=0;

        }
        yes=true;
    }
    if(psl>0){
        points=points+(psl*(psl+1)/2);
    }
    cout<<points<<endl;

}
