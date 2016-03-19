#include <iostream>
#include <algorithm>
using std::size_t;
static const size_t N=64;
static void input(std::istream &in, char *out){
    do{
        char ch=in.peek();
        if(ch!=' ' && ch!='\n' && ch!='\t' && ch!='\r') break;
        in.get();
    }while(true);
    size_t i;
    for(i=0;i<N;i++){
        char ch;
        ch=in.peek();
        if(ch=='0'){
            out[i]=0;
        }else if(ch=='1'){
            out[i]=1;
        }else if(ch=='?'){
            out[i]=-1;
        }else{
            break;
        }
        in.get();
    }
    std::reverse(out, out+i);
    for(;i<N;i++){
        out[i]=0;
    }
}
static void output(std::ostream &out, char *in){
    size_t i=N-1;
    while(in[i]==0){
        i--;
        if(i==0){
            out<<'0';
            return;
        }
    }
    do{
        if(in[i]==-1) out<<'?';
        else out<<char('0'+in[i]);
    }while(i--);
}
static void adder(char *out, const char *in1, const char *in2){
    char carry=0;
    for(size_t i=0;i<N;i++){
        char vMin=char(carry>0)+char(in1[i]>0)+char(in2[i]>0);
        char vMax=char(carry!=0)+char(in1[i]!=0)+char(in2[i]!=0);
        if(vMin==vMax){
            out[i]=vMin%2;
        }else{
            out[i]=-1;
        }
        if(vMin<2&&vMax<2){
            carry=0;
        }else if(vMin>=2&&vMax>=2){
            carry=1;
        }else{
            carry=-1;
        }
    }
    return;
}
int main(){
    char n1[N], n2[N], n3[N];
    input(std::cin, n1);
    input(std::cin, n2);
    adder(n3, n1, n2);
    output(std::cout, n3);
    std::cout<<'\n';
}
