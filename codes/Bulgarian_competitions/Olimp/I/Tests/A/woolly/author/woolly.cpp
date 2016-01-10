#include <iostream>
#include <cstring>
#pragma GCC diagnostic ignored "-Wchar-subscripts"
using namespace std;
typedef struct
{char d[64];
 int len;
} Addend;
char b[64];
Addend a,r;
void getAddend(const char *b,Addend *a)
{a->len=strlen(b);
 for (int i=a->len-1,j=0;i>=0;i--,j++)
  if (b[i]!='?') a->d[j]=b[i]-'0';
  else a->d[j]=2;
}
void showAddend(const Addend *a)
{for (int i=a->len-1;i>=0;i--)
  if (a->d[i]!=2) cout<<(int)a->d[i];
  else cout<<'?';
}
char addInsecureBinDigits(char a,char b,char *carry)
{char s[3];
 for (int i=0;i<3;i++) s[i]=0;
 s[a]++;s[b]++;s[*carry]++;
 if (!s[2]){a+=b+*carry;
     *carry=(a>>1);
     return a&1;
    }
 for (int i=0;i<3;i++) if(s[i]>=2){*carry=i;return 2;}
 *carry=2; return 2;
}
void addTo(Addend *a,const Addend *b)
{char carry=0;
 int t=(a->len>b->len)?a->len:b->len;
 for (int i=0;i<t;i++)
 {char c=(i<a->len)?a->d[i]:0;
  char d=(i<b->len)?b->d[i]:0;
  a->d[i]=addInsecureBinDigits(c,d,&carry);
 }
 a->len=t;
 if (carry) a->d[a->len++]=carry;
}

int main()
{cin>>b;
 getAddend(b,&r);
 cin>>b;
 getAddend(b,&a);
 addTo(&r,&a);
 showAddend(&r);
 cout<<endl;
 return 0;
}
