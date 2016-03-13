#include<iostream>
#include<algorithm>
using namespace std;
int main (){
long long uchenitsi=0,poznanstva=0,broyach=0,purvi=0,vtori=0,broyach2=0;
cin>>uchenitsi>>poznanstva;
long long matritsa[uchenitsi],poznati[uchenitsi][uchenitsi];
long long broi=0;
bool minali=0,minati[uchenitsi];
for(broyach=0;broyach<uchenitsi;broyach++){
        for(broyach2=0;broyach2<uchenitsi;broyach2++){
           poznati[broyach][broyach2]=0;
        }
}
for(broyach=0;broyach<uchenitsi;broyach++){

 matritsa[broyach]=0;
 minati[broyach]=0;
}
for(broyach=0;broyach<poznanstva;broyach++){
 cin>>purvi>>vtori;

    poznati[purvi-1][vtori-1]=1;
 }
for(broyach=0;broyach<uchenitsi;broyach++){
        for(broyach2=0;broyach2<uchenitsi;broyach2++){
         if(poznati[broyach2][broyach]==1 or poznati[broyach][broyach2]==1){
            matritsa[broyach]+=matritsa[broyach2];
            matritsa[broyach]++;
         }

        }

}
sort(matritsa,matritsa+uchenitsi);
if(matritsa[uchenitsi-1]==2 and uchenitsi%2==0){
    cout<<uchenitsi/2<<endl;
}else{
    if(matritsa[uchenitsi-1]==2 and uchenitsi%2==0){
       cout<<uchenitsi/2-1<<endl;
    }else{
if(uchenitsi+1-matritsa[uchenitsi-1]<1){
cout<<1<<endl;
}else{
cout<<uchenitsi+1-matritsa[uchenitsi-1]<<endl;
}
    }
}
return 0;
}
