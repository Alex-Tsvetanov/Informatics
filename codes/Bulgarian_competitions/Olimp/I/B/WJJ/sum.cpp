#include<iostream>

using namespace std;
int number;
int main()
{  
   int input;
   cin>>input;

   if(input%2 == 0) {
    cout<<input;
   }
    
   if(input%2 != 0) {
    cout<<input-1;
   }
    return 0;
}