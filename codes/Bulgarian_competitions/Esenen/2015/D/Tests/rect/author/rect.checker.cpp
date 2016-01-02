#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
int a[3],b[3], cw,ch;
char lab[1024][1024];
void findChar(char c,int *row,int *col)
{*row=1;
 do
 {*col=1;
  do
  {
  if (lab[*row][*col]==c) return;
  (*col)++;
  }while (*col<cw-1);
  (*row)++;
 }while (*row<ch-1);
 *row=*col=0;
}
int Fill(int x,int y, char n)
{if (x<=0 || y<=0 || x>=ch || y>=cw || lab[x][y]=='.' || lab[x][y]==n) return 0;
 if (lab[x][y]!=' ')return -10000;
 lab[x][y]=n;
 return 1+Fill(x+1,y,n)+Fill(x-1,y,n)+Fill(x,y+1,n)+Fill(x,y-1,n);
}
bool isRect(char c,int *w,int *h)
{int x,y,minC,minR,maxC,maxR;
 findChar(c,&minR,&minC);
 if (!minR) return false;
 for (maxR=minR;lab[maxR][minC]==c;maxR++);
 maxR--;
 for (maxC=minC;lab[minR][maxC]==c;maxC++);
 maxC--;
 for (x=minR;x<=maxR;x++)
  for (y=minC;y<=maxC;y++) if (lab[x][y]!=c) return false;
 *w=(maxC-minC+2)/2;
 *h=maxR-minR+2;
 return true;
}
bool check()
{int x,y,i,j,w,h;
 for (i=0;i<3;i++)
 {findChar(' ',&x,&y);
  if (!x) return false;
  if (Fill(x,y,'1'+i)<=0) return false;
  if (!isRect('1'+i,&w,&h)) return false;
  for (j=0;j<3;j++)
  {if ((a[j]==w &&b[j]==h) || (a[j]==h &&b[j]==w))
   {a[j]=b[j]=0;
    break;
   }
  }
  if(j>=3) return false;
 }
 return true;
}
int main(int c,char **par)
{ //if(c<5) {cout<<"Not enough parameters\n";return 0;}
  //read input data
  {ifstream f(par[1]);
   if (!f){cout<<"Input file "<<par[1]<<" not found\n"; return 0;}
   for (int i=0;i<3;i++) f>>a[i]>>b[i];
   f.ignore();
  }
  //read competitor's file
  {ifstream f(par[3]);
   if (!f){cout<<"0\nFile not found\n"; return 0;}
   for (int i=0;i<1024;i++) *lab[i]=0;
   ch=0;
   do
   {f.getline(lab[ch],1024);
    if (f.eof()) break;
    int t=strlen(lab[ch]);
    while (t>0 && lab[ch][t-1]==' ') t--;
    lab[ch][t]=0;
    for (int i=0;i<t-2;i+=2)
     if (lab[ch][i]=='.' && lab[ch][i+2]=='.' && lab[ch][i+1]==' ')lab[ch][i+1]='.';
    ch++;
   }while(true);
  }
  cw=strlen(lab[0]);
  if (!cw){cout<<"0\nInvalid output format\n"; return 0;}
  for (int i=1;i<ch;i++)
   if ((int)strlen(lab[i])!=cw){cout<<"0\nInvalid output format\n"; return 0;}
  for (int i=0;i<ch;i++) if (*lab[i]!='.' || lab[i][cw-1]!='.')
   {cout<<"0\nInvalid output format\n"; return 0;}
  for (int i=1;i<cw-1;i++) if (lab[0][i]!='.'){cout<<"0\nInvalid output format\n"; return 0;}
  for (int i=1;i<cw-1;i++) if (lab[ch-1][i]!='.'){cout<<"0\nInvalid output format\n"; return 0;}
  if (check())
    {
      cout<<1<<endl;
      cerr<<"Correct\n";
    }
  else
    {
      cout<<"0\n";
      cerr << "Wrong answer\n";
    }
  return 0;
}
