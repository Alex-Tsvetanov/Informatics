#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    string a, b, rezultat = "";
    int i;
    char a_i_b_naobratno[2][64], naum = '0', rezultatat_naobratno[64];
    cin >> a >> b;
    for(i=0; i<a.size(); i++){
        a_i_b_naobratno[0][i] = a[a.size()-i-1];
    }
    for(i=0; i<b.size(); i++){
        a_i_b_naobratno[1][i] = b[b.size()-i-1];
    }
    if(a.size() < b.size()){
        for(i=a.size(); i<=b.size(); i++){
            a_i_b_naobratno[0][i] = '0';
        }
        a_i_b_naobratno[1][b.size()] = '0';
    }else{
        for(i=b.size(); i<=a.size(); i++){
            a_i_b_naobratno[1][i] = '0';
        }
        a_i_b_naobratno[0][a.size()] = '0';
    }
    for(i=0; i<=max(a.size(), b.size()); i++){
        vector<int>sabiraemi_cifri;
        if(naum == '0' || naum == '1'){
            sabiraemi_cifri.push_back(naum - '0');
        }
        if(a_i_b_naobratno[0][i] == '0' || a_i_b_naobratno[0][i] == '1'){
            sabiraemi_cifri.push_back(a_i_b_naobratno[0][i] - '0');
        }
        if(a_i_b_naobratno[1][i] == '0' || a_i_b_naobratno[1][i] == '1'){
            sabiraemi_cifri.push_back(a_i_b_naobratno[1][i] - '0');
        }
        if(sabiraemi_cifri.size() <= 1){
            rezultatat_naobratno[i] = '?';
            naum = '?';
        }else if(sabiraemi_cifri.size() == 2){
            rezultatat_naobratno[i] = '?';
            if(sabiraemi_cifri[0] == sabiraemi_cifri[1]){
                naum = sabiraemi_cifri[0] + '0';
            }else{
                naum = '?';
            }
        }else{
            rezultatat_naobratno[i] = (sabiraemi_cifri[0] + sabiraemi_cifri[1] + sabiraemi_cifri[2])%2 + '0';
            naum = (sabiraemi_cifri[0] + sabiraemi_cifri[1] + sabiraemi_cifri[2])/2 + '0';
        }
    }
    if(rezultatat_naobratno[max(a.size(), b.size())] != '0'){
        rezultat += rezultatat_naobratno[max(a.size(), b.size())];
    }
    for(i=max(a.size(), b.size())-1; i>=0; i--){
        rezultat += rezultatat_naobratno[i];
    }
    cout << rezultat << '\n';
    return 0;
}
