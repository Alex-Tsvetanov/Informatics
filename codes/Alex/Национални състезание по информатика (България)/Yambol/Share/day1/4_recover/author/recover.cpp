#include <stdio.h>
#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    char buff[121], w[121], digit[]="0123456789", form[]="%dX%d=%d";
    bool dflag;
    int i,op1,op2,op3, solnum=0;
    char act;
    scanf("%s" , buff);
    dflag = false;
    for(i=0; ;i++){
       if(isdigit(buff[i]) || buff[i]=='#'){ dflag=true; }
       if(dflag){
         if(buff[i]=='-'||buff[i]=='+'||buff[i]=='*'||buff[i]=='/'){
            act = buff[i];form[2]=act;
            break;
         }
       }
    }
    for(int k=9; k>=0; k--){
       strcpy(w, buff);
       for(i=0; w[i]; i++)if(w[i] == '#')w[i]= digit[k];
       sscanf(w, form, &op1, &op2, &op3);
       //cout<<op1<<act<<op2<<"="<<op3<<endl;
       dflag = false;
       switch(act){
                case '+': if(op1+op2 == op3){dflag=true; }
                          break;
                case '-': if(op1-op2 == op3){dflag=true; }
                          break;
                case '*': if(op1*op2 == op3){dflag=true; }
                          break;
                case '/': if((op2!=0) && (op1/op2 == op3)){dflag=true; }
                          break;
      }
     if(solnum>0)cout<<" ";
     if(dflag){cout<<digit[k]; solnum++;}
    }
    if(solnum==0) cout<<"wrong";
    cout<<endl;
    return 0;
}
