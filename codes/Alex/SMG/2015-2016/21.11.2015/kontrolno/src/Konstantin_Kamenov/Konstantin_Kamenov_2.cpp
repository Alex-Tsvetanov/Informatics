#include<iostream>
#include<algorithm>
using namespace std ;
int main (  ) {
    string b;
    cin>>b;
    string a,c;
    sort(b.begin(),b.end());
    a=b;
    c=b;
    reverse(c.begin(),c.end());
    int naum=0;
    int nullcount=0;
    char nula='0';
    for(int i=0;a[i]=='0';i++){
        nullcount++;
    }
    a=a.substr(nullcount,a.size());
    for(int i=0;i<nullcount;i++){
        a.insert(1,"0");
    }
    string res="";
    for(int i=b.size()-1;i>=0;i--){
        char cif=(a[i]-'0'+c[i]+naum);
        if(cif>'9'){
            naum=1;
            cif-=10;
        }
        res+=cif;
    }
    if(naum){
        res+='1';
    }
    reverse(res.begin(),res.end());
    cout<<res<<endl;
    return 0 ;
}
