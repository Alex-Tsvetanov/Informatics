#include <stdio.h>
char P[2048],data[1024];
inline char NAND(char b1,char b2){return (b1&b2)^(char)1;}
//Стек от символи
struct {int sp;
        char s[2048];
       } st={-1};
void push(char c)
{st.s[++st.sp]=c;}
char pop()
{char c=st.s[st.sp--];
 return c;
}
char top()
{return st.s[st.sp];
}
//Превръщане в обратен полски запис
char *toPolish(const char *E, char *P)
{int i=0,j=0;
 char c;
 st.sp=-1;
 for (i=0;E[i];i++)
 {//ако се подразбира предишен оператор
  if (E[i]!=')' && i>0 && (E[i-1]>='a'||E[i-1]==')'))
  {if (st.sp<0 || top()=='(') push('@');
   else P[j++]='@';   
  }
  //променлива: директно се преписва
  if (E[i]>='a') {P[j++]=E[i];
                  continue;
                 }
  //отваряща скоба: в стека
  if (E[i]=='(') {push('(');
                  continue;
                 }
  //затваряща скоба: всичко от стека до (
  c=pop();
  while (c!='(')
  {P[j++]=c;
   c=pop();   
  }
 }
 //докато има още операции в стека
 while (st.sp>=0) P[j++]=pop();
 P[j]=0;
 return P;
};
//Изчисляване от обратния полски запис
char CalcPolish()
{int i;
 st.sp=-1;
 push(data[*P-'a']);
 for (i=1;P[i];i++)
 {if (P[i]=='@') push(NAND(pop(),pop()));
  else push(data[P[i]-'a']);
 }
 return pop();
}
int main()
{scanf("%s",data);
 toPolish(data,P);
 do
 {scanf("%s",data);
  if (*data=='2') break;
  printf("%c",CalcPolish());   
 }while(1);
 printf("\n");
 return 0;
}