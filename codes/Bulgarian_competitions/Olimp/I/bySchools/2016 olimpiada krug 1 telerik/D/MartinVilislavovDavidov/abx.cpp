#include<iostream>
using namespace std;
int main(){
long long a,b,chislo_1,chislo_2,chislo_3,razlika_1,razlika_2;
char plys='+',eravno='=',x='X';

cin>>chislo_1;
cin>>plys;
cin>>chislo_2;
cin>>eravno;
cin>>chislo_3;

//cout<<" 1:"<<chislo_1<<" 2:"<<chislo_2<<" 3:"<<chislo_3;




if(chislo_1=='X'){
    cout<<razlika_1<<endl;
    chislo_1='X';
    cout<<"NESTO4";
}
if(chislo_2=='X'){
    cout<<razlika_2<<endl;
    chislo_2='X';
    cout<<"NESTO5";
}



if(chislo_1=='X'){
    chislo_1=='X';
    a=chislo_2;
    cout<<"NESTO";
}else{
    a=chislo_1;
    chislo_2=='X';
    cout<<"NESTO1";
}




cout<<razlika_1;//=chislo_3-chislo_2;
cout<<razlika_2;//=chislo_3-chislo_1;



return 0;
}
