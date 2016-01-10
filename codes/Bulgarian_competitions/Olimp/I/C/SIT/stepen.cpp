#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
int main(){
long long chislo=0,broyach=0,naigolqmo=0,broyach2=0,naimalko=0,otg=0;
long long broyach3=0,broyach4=0,chislo2=0,br=0;
cin>>chislo;
chislo2=chislo;
long long broi[100000],novbroi[100000],otgovarqsht[100][100];
for(broyach=2;broyach<100000;broyach++){
broi[broyach]=0;
novbroi[broyach]=0;

}
for(broyach=0;broyach<100;broyach++){
    for(broyach2=0;broyach2<100;broyach2++){
        otgovarqsht[broyach][broyach2]=0;
    }
}
for(broyach=2;chislo>1;broyach++){

if(chislo%broyach==0){

    chislo/=broyach;
broi[broyach]++;
broyach=1;
}

}
for(broyach=0;broyach<100000;broyach++){

    if(broi[broyach]!=0 and broi[broyach]>naigolqmo){
        naigolqmo=broi[broyach];
    }
}
if(naigolqmo==1){
    cout<<0<<endl;
}else{
for(broyach=0;broyach<100000;broyach++){

  if(broi[broyach]>0){

   novbroi[broyach2]=broi[broyach];
    broyach2++;
  }
  }
naimalko=novbroi[0];
for(broyach=1;broyach<broyach2;broyach++){

    if(novbroi[broyach]<naimalko){
      naimalko=novbroi[broyach];
    }
}

for(broyach=2;broyach<=naimalko;broyach++){

  for(broyach3=0;broyach3<broyach2;broyach3++){
    if(novbroi[broyach3]%broyach==0){
        broyach4++;
    }
  }


  if(broyach2==broyach4){

    otg++;
  }
for(br=2;br<=chislo/broyach;br++){

    if(pow(br,broyach)==chislo2){
otgovarqsht[br][broyach]=1;

    }
}
  broyach4=0;
}

cout<<otg<<endl;
for(broyach2=0;broyach2<100;broyach2++){
    for(broyach=0;broyach<100;broyach++){
       if(otgovarqsht[broyach][broyach2]==1){
        cout<<broyach<<" "<<broyach2<<endl;
       }
    }
}
}

return 0;
}
