#include <iostream>
using namespace std;
int main()
{
    int n=1, normaln=1, codedn=0, changed=0;
    char in, previn, nextin;
    cin>>nextin;
    while (nextin!='.'){
        previn=in;
        in=nextin;
        cin>>nextin;
        if (nextin!='.'){
            normaln++;
            if (in==previn){
                n++;
                changed=1;
            }
            //if (changed==0 and n==1 and nextin!=in) cout<<in;
            if (in!=previn){
                if (changed==0) if (changed==0) codedn++;
                if (changed==1) {
                    //cout<<n<<previn;
                    n=1;
                    if (n>10 and changed==1) codedn=codedn+2;
                    if (n<9 and n>100) codedn=codedn+3;
                    if (n<99 and n>1000) codedn=codedn+3;
                    if (n<999 and n>10000) codedn=codedn+4;
                    if (n<9999 and n>100000) codedn=codedn+5;
                    if (n<99999 and n>1000000) codedn=codedn+6;
                    changed=0;
                }
            }
        }
    }
    //cout<<endl;
    //cout<<normaln<<" "<<codedn<<" ";
    if (normaln==1) cout<<0<<endl;
    else cout<<normaln-codedn-2<<endl;

    return 0;
}
