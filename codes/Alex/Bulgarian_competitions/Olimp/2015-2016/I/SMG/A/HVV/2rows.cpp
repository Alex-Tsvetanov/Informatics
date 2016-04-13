#include <iostream>
#include <algorithm>
using std::size_t;
unsigned seqA[1<<17], sortedA[1<<17];
static bool solve(){
    size_t lA, lB;
    std::cin>>lA;
    for(size_t i=0;i<lA;i++){
        std::cin>>seqA[i];
        sortedA[i]=seqA[i];
    }
    std::sort(sortedA, sortedA+lA);
    std::cin>>lB;
    size_t j=0;
    bool ok=true;
    for(size_t i=0;i<lB;i++){
        unsigned el;
        std::cin>>el;
        if(ok&&std::binary_search(sortedA, sortedA+lA, el)){
            while(seqA[j]!=el){
                j++;
                if(j==lA){
                    ok=false;
                    break;
                }
            }
        }
    }
    return ok;
}
int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    for(size_t i=0;i<5;i++) std::cout<<(int)solve();
    std::cout<<'\n';
    return 0;
}
