#include <iostream>
#include <cstring>
#pragma GCC diagnostic ignored "-Wchar-subscripts"
using namespace std;
char d[2][64],//���������
     *offs[2][64],//����������� �� ?
     cnt[2],//���� ? �� ���������
     len,maxLen=0;//���������� ������� �� ����
     
int comm=0;//��� ���� ? 
long long sum[64]={0}, //���� �� ����� �������
          bin[2]; //������� ����� �� �������� ��������� �� ? �� ���������

int main()
{//�������������
 for (int i=0;i<2;i++)
 {for (int j=0;j<64;j++) d[i][j]=0;
  bin[i]=0;   
 }
 for (int i=0;i<2;i++)
 {//���������
  cin>>d[i];
  len=strlen(d[i]);
  cnt[i]=0;//����� �� ?
  if (len>maxLen) maxLen=len;
  //�������� �� ������
  for (char *p=d[i],*q=&d[i][len-1];p<q;p++,q--)
  {char c=*p;
   *p=*q;
   *q=c;
  }   
  //������� �� ?
  for(char *p=d[i];*p;p++) if (*p=='?'){offs[i][cnt[i]++]=p;
                                        *p=0;
                                       }
                           else *p-='0';            
  comm+=cnt[i];
 }
 //���������
 do
 {int i;
  char r[64];//��������
  int c=0;//������
  for (int i=0;i<=maxLen;i++)r[i]=0;//�������� �� ���������
  //��������
  for (int i=0;i<maxLen;i++)
  {for (int j=0;j<2;j++)c+=d[j][i];
   r[i]=c & 1;
   c>>=1;
  }
  if(c) r[maxLen++]=1;//��� ��� ������
  for (int i=0;i<maxLen;i++)sum[i]+=r[i];
  for (i=0;i<2;i++)
   if (bin[i]<((long long)1<<cnt[i])-1) break;
   else bin[i]=0;
  if (i>=2) break; 
  bin[i]++;
  //��� ����� �� ��������� �� ?
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
