#include<iostream>
#include<string>
using namespace std;
int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(NULL);
    long long brImena,br,sre6taniq=0,brGlaven=0;
    string glaven,tekusto;
    cin>>brImena;
    for(br=0;br<brImena;br++){
        cin>>tekusto;
        if(brGlaven==0){
            glaven=tekusto;
            brGlaven++;
        }else if(tekusto!=glaven){
            brGlaven--;
        }
    }
    cout<<glaven<<"\n";
    return 0;
}
