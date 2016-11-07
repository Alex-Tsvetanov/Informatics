#include <iostream>
int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    char s[16384];
    unsigned v[16384];
    size_t pstart[16384], pstartn=0;
    std::cin>>s;
    v[0]=0;
    size_t i;
    for(i=1;s[i];i++){
        size_t k=0;
        for(size_t j=(pstart[0]==0?1:0);j<pstartn;j++){
            size_t p=pstart[j];
            p--;
            if(s[p]!=s[i]) continue;
            pstart[k++]=p;
        }
        if(s[i-1]==s[i]) pstart[k++]=i-1;
        pstart[k++]=i;
        pstartn=k;
        if(pstart[0]==0) v[0]=0;
        else{
            v[i]=-1;
            for(size_t j=0;j<pstartn;j++){
                size_t p=pstart[j]-1;
                if(v[p]<v[i]) v[i]=v[p];
            }
            v[i]++;
        }
    }
    std::cout<<v[i-1]<<'\n';
    return 0;
}
