#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;
struct pazach{
    int x, y, index;
    pazach(int x0, int y0, int index0){
        x = x0;
        y = y0;
        index = index0;
    }
};
bool cmp(pazach p1, pazach p2){
    if(atan2(p1.y, p1.x) - atan2(p2.y, p2.x) < 0.0001 && atan2(p1.y, p1.x) - atan2(p2.y, p2.x) > -0.0001){
        return p1.index < p2.index;
    }
    return atan2(p1.y, p1.x) < atan2(p2.y, p2.x);
}
double radtodeg(double alpha){
    return (180/3.14159) * alpha;
}
int main(){
    int cx, cy, p1x[3], p1y[3], p2x[3], p2y[3], i, br=0, procenti;
    double obshto_sledena_chast = 0;
    pazach parvi(0, 0, 0);
    vector<pazach>pazeshti;
    cin >> cx >> cy;
    for(i=0; i<3; i++){
        cin >> p1x[i] >> p1y[i] >> p2x[i] >> p2y[i];
    }
    for(i=0; i<3; i++){
        p1x[i] -= cx;
        p1y[i] -= cy;
        p2x[i] -= cx;
        p2y[i] -= cy;
        pazeshti.push_back(pazach(p1x[i], p1y[i], 1));
        pazeshti.push_back(pazach(p2x[i], p2y[i], -1));
    }
    sort(pazeshti.begin(), pazeshti.end(), cmp);
    if(pazeshti[5].index == 1){
        obshto_sledena_chast = 360 - radtodeg(atan2(pazeshti[5].y, pazeshti[5].x) - atan2(pazeshti[0].y, pazeshti[0].x));
        br++;
    }
    for(i=0; i<=5; i++){
        if(br == 0 || (i==0 && pazeshti[0].index == 1)){
            parvi = pazeshti[i];
        }
        br += pazeshti[i].index;
        if(br == 0 && !(i==0 && pazeshti[0].index == -1)){
            obshto_sledena_chast += radtodeg(atan2(pazeshti[i].y, pazeshti[i].x) - atan2(parvi.y, parvi.x));
        }
    }
    procenti = (obshto_sledena_chast/360)*100-floor((obshto_sledena_chast/360)*100)<0.5? floor((obshto_sledena_chast/360)*100):floor((obshto_sledena_chast/360)*100)+1;
    cout << procenti << '\n';
    return 0;
}
