#include<iostream>
using namespace std;
int mod(int a)
{
    if(a<0)
    {
        return 0-a;
    }
    return a;
}
int main()
{
   long long rows,columns,col,row;
   string a;
   cin>>a;
   columns=a[0]-'a'+1;
   if(a.size()<3)
   {
      rows=a[1]-'0';
   }
   else
   {
      rows=(a[1]-'0')*10+(a[2]-'0');
   }
   //cout<<rows<<" "<<columns<<"\n";
   cin>>a;
   col=a[0]-'a'+1;
   if(a.size()<3)
   {
      row=a[1]-'0';
   }
   else
   {
      row=(a[1]-'0')*10+(a[2]-'0');
   }
   //cout<<row<<" "<<col<<"\n";
   char pole[rows+1][columns+1];
   for(int j=1;j<=rows;j++)
   {
       for(int k=1;k<=columns;k++)
       {
           if((mod(row-j)==1&&mod(col-k)==2)
              ||(mod(row-j)==2&&mod(col-k)==1))
           {
               pole[j][k]='X';
           }
           else
           {
               pole[j][k]='O';
           }
       }
   }
   pole[row][col]='H';
   cout<<"   ";
   for(int g=0;g<columns;g++)
   {
      cout<<char('a'+g);
   }
   cout<<"\n";
   for(int j=1;j<=rows;j++)
   {
       if(j<=9)
       {
         cout<<" "<<j<<" ";
       }
       else
       {
           cout<<j<<" ";
       }
       for(int k=1;k<=columns;k++)
       {
          cout<<pole[j][k];
       }
       cout<<"\n";
   }
   return 0;
}

