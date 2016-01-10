#include<iostream>
#include<vector>
using namespace std;
int main()
{
   int firstplace=0, secondplace=0; 
  int firstplace2=0, secondplace2=0;
  int g;
  // bool equality; 
   int minimalnum=0, maximalnum=1000000;
    vector <int> numbers;
    int noe;
    cin>>noe;
    for(int i= 0; i< noe; i++)
    {
        cin>>g;
        numbers.push_back(g);
        if(maximalnum > numbers[i]){maximalnum = numbers[i];}
        if(minimalnum < numbers[i]){minimalnum = numbers[i];}
        
    }
        
   // cout<<maximalnum<<minimalnum; //maximal = minimum minimal = maximal
     int minn = maximalnum, maxn = minimalnum;
     for(int i=0; i<noe; i++)
    {
        for(int j=0; j<noe;j++)
        {
            if(numbers[i] != minn) {break;}
           
            if(numbers[j] == maxn) {
               // if(g == j-i) {equality = true;} else{equality = false;}
             //if(secondplace - firstplace <= j-i && ) { /*g=j-i;*/ firstplace = i; secondplace =j;}
            if(secondplace - firstplace <= j-i) { /*g=j-i;*/ firstplace = i; secondplace =j;}
            } 
            
        }
        
    } 
       for(int i=0; i<noe; i++)
    {
        for(int j=0; j<noe;j++)
        {
            if(numbers[i] != maxn) {break;}
           
            if(numbers[j] == minn) { //cout<<j<<"\n";
               // if(g == j-i) {equality = true;} else{equality = false;}
           //  if(secondplace - firstplace <= j-i && ) { /*g=j-i;*/ //firstplace = i; secondplace =j;}
           if(firstplace2 - secondplace2 <= j-i) { /*g=j-i;*/ firstplace2 = j; secondplace2 =i;}
            } 
        }
        }
        //cout<<firstplace2<<" "<<secondplace2;
    int s1=0, s2=0;
if(secondplace -firstplace == firstplace2 - secondplace2)
{
    for(int i = firstplace; i<secondplace; i++)
    {
        s1+=i;
    }
    for(int i = secondplace2; i<firstplace2; i++)
    {
        s2+=i;
    }
    if(s2 > s1) { cout<<firstplace+1<<" "<<secondplace+1<<'\n'; }
    if(s2 < s1) { cout<<secondplace2+1<<" "<<firstplace2+1<<'\n';}
}
else{
if(secondplace -firstplace > firstplace2 - secondplace2)
   {
       
   cout<<firstplace+1<<" "<<secondplace+1<<'\n';}
    else{
    cout<<secondplace2+1<<" "<<firstplace2+1<<'\n';
    }
}
 //}
 //else{
 
 
 //}

    return 0;
}