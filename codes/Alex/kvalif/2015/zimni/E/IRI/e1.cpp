#include<iostream>
using namespace std;
int main() {
long long obikolkaM, obikolkaSM, razlika, stranaA, stranaB, AiB, obikolkaSamoVSM, AvMetri, AvSantimetri, BvMetri, BvSantimetri;
cin>>obikolkaM>>obikolkaSM>>razlika;
obikolkaSamoVSM=obikolkaM*100+obikolkaSM;
AiB=obikolkaSamoVSM/2;
AiB=AiB/2;
stranaA=AiB-razlika/2;
stranaB=AiB+razlika/2;
if(stranaA>100){
    AvMetri=stranaA/100;
    AvSantimetri=stranaA%100;
}
if(stranaB>100){
    BvMetri=stranaB/100;
    BvSantimetri=stranaB%100;
}
cout<<AvMetri<<" "<<AvSantimetri<<endl;
cout<<BvMetri<<" "<<BvSantimetri<<endl;

return 0;
}
