#include<iostream>
using namespace std;
int main(){
long long a, b, c
;
cin>>a;
cin>>b;
cin>>c;
if(a+b==c){
 if(a-b==c){
cout<<"";
 }else{
cout<<"+";
}}
if(a-b==c){
 if(a*b==c){
cout<<"";
 }else{
cout<<"-";
}}
if(a*b==c){
 if(a+b==c){
cout<<"";
}else{
cout<<"*";}}
if(a+b!=c){
 if(a-b!=c){
  if(a*b!=c){
cout<<"0";}}}
return 0;
}
