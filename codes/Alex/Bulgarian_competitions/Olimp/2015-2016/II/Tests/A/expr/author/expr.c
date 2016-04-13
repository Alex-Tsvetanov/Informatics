#include <stdio.h>
char e[1024],data[1024];
inline char NAND(char b1,char b2){if (b1<0) return b2;
                                  if (b2<0) return b1;
                                  return (b1&b2)^(char)1;}
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
char Calc()
{int i;
 char res=-1;
 st.sp=-1;
 for (i=0;e[i];i++)
 {switch (e[i])
  {case '(':{push(res);res=-1;break;}
   case ')':{res=NAND(pop(),res);break;}
   case '0':{res='1';break;}
   default:res=NAND(res,data[e[i]-'a']);   
  }
 }
 return res;
}
int main()
{scanf("%s",e);
 do
 {scanf("%s",data);
  if (*data=='2') break;
  printf("%c",Calc());   
 }while(1);
 printf("\n");
 return 0;
}