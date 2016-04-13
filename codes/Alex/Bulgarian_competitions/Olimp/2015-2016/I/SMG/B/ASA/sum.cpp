#include <iostream>

using namespace std;
int Z;
int br;
int NMS(int s){
    int i=0;
    int sborr=1;
    for(i; sborr<=s; i++){
        sborr = sborr*2;
    }
    return i-1;
}
int stepenuwane(int s){
    int stepen=1;
    for(int i=0;i<s;i++){
        stepen = stepen*2;
    }
    return stepen;
}
int f(int chislo){
    int sbor=0;
    if(chislo == 0) return 1;
    if(chislo == 1) return 1;
    int nms = NMS(chislo);
    for(int i=nms; i>=0; i--){
        if(i!=0){
            sbor = sbor + f(chislo - stepenuwane(i));
        }else{
            sbor++;
        }
        if(i>1) br++;
    }
    return sbor;
}
int main()
{
    cout << f(7) - br/2;
    return 0;
}
