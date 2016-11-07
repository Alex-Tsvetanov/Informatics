#include<iostream>
#include<cstring>
const int BNum = 61;
int main()
{
    std::string a,b;
    std::cin>>a>>b;
    a="0"+a;
    int aS=a.length(), bS=b.length();
    if(aS<bS)
    {
        std::swap(a, b);
        std::swap(aS, bS);
    }
    for(int i=0; i<aS-bS; ++i) b="0"+b;
    for(int i=1; i<aS; ++i)
    {
        char ai = a[aS-i], bi = b[aS-i];
        if(ai=='?'){
            if(bi=='?')
                a[aS-i]='1';
            else {
                a[aS-i]=bi;
                b[aS-i]='?';
            }
        }
        else {
            if(bi=='1'){
                a[aS-i]+=1;
                b[aS-i]='0';
            }
        }
    }
    for(int i=1; i<aS; ++i){
        if(a[aS-i]>'1'){
            a[aS-i]='0'+(a[aS-i]-'0')%2;
            a[aS-i-1]+=1;
        }
    }
    bool prenos = false;
    for(int i=1; i<=aS; ++i)
    {
        char ai = a[aS-i], bi = b[aS-i];
        if(bi=='?'){
            a[aS-i]='?';
            if(ai=='1')
                prenos=true;
        }
        else{
            if(prenos==true){
                a[aS-i]='?';
                if(ai=='0')
                    prenos=false;
            }
        }
    }
    if(a[0]=='0') a=a.substr(1, aS-1);
    std::cout<<a<<'\n';
    return 0;
}
