#include <iostream>
using namespace std;
int main()
{
    int bukva,bukva1,i,n,razlika=0,br=0;
    cin>>bukva;
    while(n!=0 && n!='.')
    {
     for(i='a'; n<'z'; i++)
     {    
          cin>>bukva;
        if(bukva=bukva+bukva1)
        {
          br++;        
        }                  
     }
      cin>>bukva;
       if(bukva>'.')
       {  
         razlika++;  
       }                
    } 
    cout<<razlika<<endl;          
    return 0;
    }
