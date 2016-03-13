#include <iostream>
#include <cmath>
#include <algorithm>
#include <iomanip>
typedef long double Flt;
static Flt area(Flt a, Flt w, Flt h){
    return w*h*(2-1/std::cos(a))+std::sin(a)/(2*std::cos(a)*(1+std::cos(a)))*(h*h+w*w);
}
int main(){
    Flt w, h;
    std::cin>>w>>h;
    if(w<h) std::swap(w, h);

    Flt critA=2*std::atan2(h, w);
    Flt limL=0, limR=critA;
    for(size_t i=0;i<256;i++){
        Flt midA=(2*limL+limR)/3, midB=(limL+2*limR)/3;
        Flt valA=area(midA, w, h), valB=area(midB, w, h);
        if(valA>valB){
            limR=midB;
        }else{
            limL=midA;
        }
    }
    Flt c1=2*w*h-h*h, c2=area(limL, w, h);
    std::cout<<std::fixed<<std::setprecision(3)<<std::max(c1, c2)<<'\n';
    return 0;
}
