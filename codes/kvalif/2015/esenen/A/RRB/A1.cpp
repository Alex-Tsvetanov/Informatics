#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;
struct drob{
    int chislitel, znamenatel;
    drob(){
        chislitel = 1;
        znamenatel = 1;
    }
    drob(int c, int z){
        chislitel = c;
        znamenatel = z;
    }
};
void napravi_znamenatelya_polozhitelen(drob d){
    if(d.znamenatel < 0){
        d.chislitel *= -1;
        d.znamenatel *= -1;
    }
}
bool operator < (drob d1, drob d2){
    napravi_znamenatelya_polozhitelen(d1);
    napravi_znamenatelya_polozhitelen(d2);
    if(d1.chislitel<0 && d2.chislitel>0){
        return true;
    }
    if(d1.chislitel>0 && d2.chislitel<0){
        return false;
    }
    return d1.chislitel*d2.znamenatel < d2.chislitel*d1.znamenatel;
}
bool operator==(drob d1, drob d2){
    return d1.chislitel*d2.znamenatel == d2.chislitel*d1.znamenatel;
}
drob operator*(drob d1, drob d2){
    drob d;
    d.chislitel = d1.chislitel*d2.chislitel;
    d.znamenatel = d1.znamenatel*d2.znamenatel;
    return d;
}
drob operator/(drob d1, drob d2){
    drob d;
    d.chislitel = d1.chislitel*d2.znamenatel;
    d.znamenatel = d2.chislitel*d1.znamenatel;
    return d;
}
drob operator+(drob d1, drob d2){
    drob d;
    d.chislitel = d1.chislitel*d2.znamenatel + d2.chislitel*d1.znamenatel;
    d.znamenatel = d1.znamenatel*d2.znamenatel;
    return d;
}
drob operator-(drob d1, drob d2){
    drob d;
    d.chislitel = d1.chislitel*d2.znamenatel - d2.chislitel*d1.znamenatel;
    d.znamenatel = d1.znamenatel*d2.znamenatel;
    return d;
}
int main(){
    int n, i, x[2001], y[2001];
    vector<pair<drob, int> >tangens_i_poreden_nomer;
    vector<pair<drob, int> >tangens_i_poreden_nomer_IV_i_I_kvadrant;
    drob edno(1, 1), minus_edno(-1, 1);
    vector<pair<drob, pair<drob, int> > >tangensi_na_aglite;
    vector<pair<drob, pair<drob, int> > >tangensi_na_tapite_agli;
    cin >> n;
    for(i=0; i<=n; i++){
        cin >> x[i] >> y[i];
    }
    for(i=0; i<=n; i++){
        x[i] -= x[0];
        y[i] -= y[0];
    }
    for(i=1; i<=n; i++){
        drob d(y[i], x[i]);
        if(x[i] == 0){
            d.chislitel = y[i]>0?100001:-100001;
            d.znamenatel = 1;
        }
        if(x[i]<0){
            tangens_i_poreden_nomer.push_back(make_pair(d, i));
        }else{
            tangens_i_poreden_nomer_IV_i_I_kvadrant.push_back(make_pair(d, i));
        }
    }
    sort(tangens_i_poreden_nomer.begin(), tangens_i_poreden_nomer.end());
    sort(tangens_i_poreden_nomer_IV_i_I_kvadrant.begin(), tangens_i_poreden_nomer_IV_i_I_kvadrant.end());
    for(i=0; i<tangens_i_poreden_nomer_IV_i_I_kvadrant.size(); i++){
        tangens_i_poreden_nomer.push_back(tangens_i_poreden_nomer_IV_i_I_kvadrant[i]);
    }
    for(i=0; i<tangens_i_poreden_nomer.size()-1; i++){
        drob tangens;
        if(tangens_i_poreden_nomer[i].first * tangens_i_poreden_nomer[i+1].first == minus_edno){
            tangens.chislitel = 100001;
            tangens.znamenatel = 1;
        }else if(tangens_i_poreden_nomer[i].first.chislitel == 100001 || tangens_i_poreden_nomer[i].first.chislitel == -100001){
            tangens.chislitel = -tangens_i_poreden_nomer[i+1].first.znamenatel;
            tangens.znamenatel = tangens_i_poreden_nomer[i+1].first.chislitel;
        }else if(tangens_i_poreden_nomer[i+1].first.chislitel == 100001 || tangens_i_poreden_nomer[i+1].first.chislitel == -100001){
            tangens.chislitel = tangens_i_poreden_nomer[i].first.znamenatel;
            tangens.znamenatel = tangens_i_poreden_nomer[i].first.chislitel;
        }else{
            tangens = (tangens_i_poreden_nomer[i+1].first - tangens_i_poreden_nomer[i].first)/(edno+tangens_i_poreden_nomer[i].first*tangens_i_poreden_nomer[i+1].first);
        }
        if(tangens.chislitel>=0){
            tangensi_na_aglite.push_back(make_pair(tangens, tangens_i_poreden_nomer[i]));
        }else{
            tangensi_na_tapite_agli.push_back(make_pair(tangens, tangens_i_poreden_nomer[i]));
        }
    }
    sort(tangensi_na_aglite.begin(), tangensi_na_aglite.end());
    sort(tangensi_na_tapite_agli.begin(), tangensi_na_tapite_agli.end());
    for(i=0; i<tangensi_na_tapite_agli.size(); i++){
        tangensi_na_aglite.push_back(tangensi_na_tapite_agli[i]);
    }
    return 0;
}
