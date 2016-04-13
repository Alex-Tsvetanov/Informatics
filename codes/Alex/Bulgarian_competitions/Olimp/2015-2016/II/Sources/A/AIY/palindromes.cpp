#include <cstdlib>
#include <iostream>

using namespace std;
int size(char x[]){
    int length=0;
    for(int i=0;i<10000;i++){
            if(x[i]!='\0')length++;
            else break;
            }
    return length;
    }
    
bool check(char a []){
     bool isTrue=true;
    int lng=size(a);
     for(int i=0;i<lng/2; i++){
             if(a[i]==a[lng-i-1]){isTrue=true;}
             else{ 
                   isTrue=false;
                   break;
                   }
             }
             
             return isTrue;
     }
    
    
void countRaz(char a[]){
     int lng=size(a);
    
     int beg=lng-1;
     int br=0;
     char temp[1000];
     for(int i=lng-1;i>0;i--)
     {
      temp[i]=a[i];     
                   
     for(int j=a[beg];j>0;j--)
     {
             if(a[beg]==temp[i]){
                                 br++;
                                beg=i-1;
                                 }
             }   
             
     }
             
             
     
     
     
     cout<<br<<endl;
     } 
     
int main(int argc, char *argv[])
{
   
    char enter[10000];
    cin>>enter;
   
    if(check(enter)){
                     cout<<"0"<<endl;                     
                     }
                     else{
                          countRaz(enter);
                          
                          }

  //  system("PAUSE");
    return 0;
}
