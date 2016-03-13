#include<iostream>
using namespace std;
int main(){
long n,m,j,poziciq,obshto,t;
bool b=0;
cin>>n>>m;
long skok[m],i;
for(i=0;i<m;i++){
cin>>skok[i];
}
long long putechka[n];
long long vuzmojenbroi[n],mqsto[n];
for(i=0;i<=n;i++){
cin>>putechka[i];
}
poziciq=0;

for(i=0;i<m;i++){
    if(skok[i]==1){
        b=1;
        obshto=putechka[0];
    }

}
if(b==1){
    for(i=1;i<=n;i++){
        obshto=obshto+putechka[i];
poziciq=i;
    }
    cout<<obshto<<" "<<poziciq;
}else{
    obshto=0;
for(j=0;j<m;j++){
for(i=0;i<=n;i=i+skok[j]){
    obshto=obshto+putechka[i];
}
vuzmojenbroi[j]=obshto;
obshto=0;
}

for(i=0;i<m;i++){
        for(j=0;j<m;j++){
    if(vuzmojenbroi[j]>vuzmojenbroi[i]){
        t=vuzmojenbroi[i];
        vuzmojenbroi[i]=vuzmojenbroi[j];
        vuzmojenbroi[j]=t;
    }

}
}

cout<<vuzmojenbroi[m-1];
}

return 0;
}
