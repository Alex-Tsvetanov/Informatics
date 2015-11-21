#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

char a[1000],b[1000],c[1000];
long long dulzina;

bool cmpMax(char p,char q){
    return p>q;
}

bool cmpMin(char p,char q){
    return p<q;
}


int main(){
    cin>>a;
    dulzina=strlen(a);
    strcpy(b,a);
    sort(a,a+dulzina,cmpMax);
    long long br,br1,brNuli=0,index=0;
    for(br=0;br<dulzina;br++){
        if(a[br]=='0'){
            brNuli++;
        }else{
            b[index]=a[br];
            index++;
        }
    }
    sort(b,b+index);
    strcpy(c,b);
    if(brNuli!=0){
        for(br=0;br<index;br++){
            if(c[br]!=b[0]){
                for(br1=br;brNuli>0;br1++){
                    c[br1]='0';
                    brNuli--;
                }
                for(;br1<dulzina;br1++){
                    c[br1]=b[br];
                    br++;
                }
                br=index;
            }
        }
    }
    //cout<<a<<"\n"<<c<<endl;
    long long cifra,naum=0,p,q;
    for(br=dulzina-1;br>=0;br--){
        p=a[br]-'0';
        q=c[br]-'0';
        cifra=p+q+naum;
        naum=cifra/10;
        //cout<<p<<" "<<q<<" "<<cifra<<" "<<naum<<endl;
        cifra%=10;
        b[br]=cifra+'0';
    }
    if(naum!=0){
        cout<<"1";
    }
    cout<<b<<"\n";
    return 0;
}
