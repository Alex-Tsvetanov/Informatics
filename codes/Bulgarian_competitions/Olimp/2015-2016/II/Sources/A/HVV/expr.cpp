#include <iostream>
#include <algorithm>
using std::size_t;
static size_t prog[26+1024][2], progstart, proglen, progshift;
static unsigned progval[26+1024];
inline static void progrun(){
    for(size_t j=progstart;j<proglen;j++) progval[j]=~(progval[prog[j][0]]&progval[prog[j][1]]);
    unsigned res=progval[proglen-1];
    for(size_t i=0;i<progshift;i++) std::cout<<((res&(1u<<i))?'1':'0');
    progshift=0;
    for(size_t i=0;i<progstart;i++) progval[i]=0;
}
int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    const size_t none=-1;

    char expr[1024];
    std::cin>>expr;

    for(size_t i=0;expr[i];i++){
        if(expr[i]>='a' && expr[i]<='z') progstart=std::max(progstart, size_t(expr[i]-'a'+1));
    }
    proglen=progstart;

    size_t stk[1024];
    size_t stklen=0;
    for(size_t i=0;expr[i];i++){
        if(expr[i] == '('){
            stk[stklen++]=none;
        }else if(expr[i] == ')'){
            size_t j;
            if(stk[stklen-1]==none) *(volatile int*)NULL=0;
            for(j=stklen-1;stk[j]!=none;j--){
                if(j==0) *(volatile int*)NULL=0;
            }
            for(size_t k=j+2;k<stklen;k++){
                prog[proglen][0]=stk[k-1];
                prog[proglen][1]=stk[k];
                stk[k]=proglen++;
            }
            stk[j]=stk[stklen-1];
            stklen=j+1;
        }else{
            stk[stklen++]=expr[i]-'a';
        }
    }
    if(stk[0]==none) *(volatile int*)NULL=0;
    for(size_t j=1;j<stklen;j++){
        if(stk[j]==none) *(volatile int*)NULL=0;
        prog[proglen][0]=stk[j-1];
        prog[proglen][1]=stk[j];
        stk[j]=proglen++;
    }
    while(true){
        std::cin>>expr;
        if(expr[0]=='2') break;
        for(size_t j=0;expr[j];j++) progval[j]|=((expr[j]=='1')?1u:0u)<<progshift;
        progshift++;
        if(progshift==32){
            progrun();
        }
    }
    if(progshift) progrun();
    std::cout<<'\n';
    return 0;
}
