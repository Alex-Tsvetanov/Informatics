#include <iostream>
#include <cmath>
using std::size_t;
static unsigned req[32768];
static int ci[16384][3];
int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    size_t n, m, q;
    std::cin>>n>>m>>q;
    for(size_t i=0;i<n;i++){
        std::cin>>ci[i][0]>>ci[i][1]>>ci[i][2];
    }
    for(size_t j=0;j<m;j++){
        int mi[2];
        std::cin>>mi[0]>>mi[1];
        for(size_t i=0;i<n;i++){
            int dx=mi[0]-ci[i][0], dy=mi[1]-ci[i][1];
            req[size_t(std::ceil(ci[i][2]+std::sqrt(dx*dx+dy*dy)))]++;
        }
    }
    for(size_t p=1;p<=20000;p++) req[p]+=req[p-1]; // max m*n
    bool dbl=false;
    unsigned total=0; // max q*(max req) == 10**9
    for(size_t i=0;i<q;i++){
        size_t r;
        std::cin>>r;
        if(dbl) r*=2;
        total+=req[r];
        dbl=(req[r]%2==0);
    }
    std::cout<<total<<'\n';
    return 0;
}
