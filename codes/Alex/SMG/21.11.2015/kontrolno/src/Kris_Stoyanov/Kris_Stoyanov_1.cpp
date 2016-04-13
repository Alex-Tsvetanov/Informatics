#include<iostream>
#include<string>
using namespace std;
int main(){
    bool daProdaljaLi=true;
    string firstTime,secondTime;
    cin>>firstTime>>secondTime;
    long long hoursInFirst,hoursInSecond,minutesInFirst,minutesInSecond,firstInMin,secondInMin,razlikaVChasove,razlikaVMinuti;
    hoursInFirst=firstTime[0]*10+firstTime[1];
    hoursInSecond=secondTime[0]*10+secondTime[1];
    minutesInFirst=firstTime[3]*10+firstTime[4];
    minutesInSecond=secondTime[3]*10+secondTime[4];
    firstInMin=60*hoursInFirst+minutesInFirst;
    secondInMin=60*hoursInSecond+minutesInSecond;
    if(firstInMin==secondInMin){
    cout<<"00:00";
    }else{
    if(minutesInFirst>minutesInSecond and hoursInFirst>hoursInSecond){
    razlikaVMinuti=60-(minutesInFirst-minutesInSecond);
    razlikaVChasove=23-(hoursInFirst-hoursInSecond);
    daProdaljaLi=false;
    }
     if(minutesInFirst<minutesInSecond and hoursInFirst>hoursInSecond and daProdaljaLi==true){
    razlikaVMinuti=minutesInSecond-minutesInFirst;
    razlikaVChasove=24-(hoursInFirst-hoursInSecond);
    daProdaljaLi=false;
    }
    if(minutesInFirst>minutesInSecond and hoursInFirst<hoursInSecond and daProdaljaLi==true){
    razlikaVMinuti=60-(minutesInFirst-minutesInSecond);
    razlikaVChasove=hoursInFirst-hoursInSecond-1;
    daProdaljaLi=false;
    }
    if(minutesInFirst<=minutesInSecond and hoursInFirst<=hoursInSecond and daProdaljaLi==true){
    razlikaVMinuti=minutesInFirst-minutesInSecond;
    razlikaVChasove=hoursInFirst-hoursInSecond;
    daProdaljaLi=false;
    }
    }
    cout<<razlikaVChasove<<":"<<razlikaVMinuti;
return 0;
}
