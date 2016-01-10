#include <iostream>
#include <cstring>
#pragma GCC diagnostic ignored "-Wchar-subscripts"
using namespace std;
char d[2][64],//събираеми
     *offs[2][64],//отмествания на ?
     cnt[2],//брой ? за събираемо
     len,maxLen=0;//максимална дължина на вход
     
int comm=0;//общ брой ? 
long long sum[64]={0}, //сума на всяка позиция
          bin[2]; //двоичен запис на текущите стойности на ? за събираемо

int main()
{//инициализация
 for (int i=0;i<2;i++)
 {for (int j=0;j<64;j++) d[i][j]=0;
  bin[i]=0;   
 }
 for (int i=0;i<2;i++)
 {//въвеждане
  cin>>d[i];
  len=strlen(d[i]);
  cnt[i]=0;//брояч на ?
  if (len>maxLen) maxLen=len;
  //обръщане на записа
  for (char *p=d[i],*q=&d[i][len-1];p<q;p++,q--)
  {char c=*p;
   *p=*q;
   *q=c;
  }   
  //позиции на ?
  for(char *p=d[i];*p;p++) if (*p=='?'){offs[i][cnt[i]++]=p;
                                        *p=0;
                                       }
                           else *p-='0';            
  comm+=cnt[i];
 }
 //Изчерпане
 do
 {int i;
  char r[64];//резултат
  int c=0;//Пренос
  for (int i=0;i<=maxLen;i++)r[i]=0;//нулиране на резултата
  //сумиране
  for (int i=0;i<maxLen;i++)
  {for (int j=0;j<2;j++)c+=d[j][i];
   r[i]=c & 1;
   c>>=1;
  }
  if(c) r[maxLen++]=1;//ако има пренос
  for (int i=0;i<maxLen;i++)sum[i]+=r[i];
  for (i=0;i<2;i++)
   if (bin[i]<((long long)1<<cnt[i])-1) break;
   else bin[i]=0;
  if (i>=2) break; 
  bin[i]++;
  //нов набор от стойности за ?
  for (;i>=0;i--)
  {long long a=bin[i];
   for (int j=0;j<cnt[i];j++)
    {*offs[i][j]=a&1;
     a>>=1;
    }
  }
 }while (true);
 for (int i=maxLen-1;i>=0;i--)
  if (!sum[i]) cout<<0;
  else if (sum[i]==((long long )1<<comm)) cout<<1;
       else cout<<'?';
  cout<<endl;     
 return 0;
}
