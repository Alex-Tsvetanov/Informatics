#include<iostream>
#include<algorithm>
using namespace std;
struct letters
{
    int c=0,lett=0;
};
bool IsLetter(char c)
{
    if((c>='a')&&(c<='z'))
    {
        return true;
    }
    else if((c>='A')&&(c<='Z'))
    {
        return true;
    }
    return false;
}
int Which(char c)
{
    if((c>='a')&&(c<='z'))
    {
        return int(c)-'a';
    }
    else if((c>='A')&&(c<='Z'))
    {
        return int(c)-'A';
    }
    return -1;
}
bool Sort(letters a,letters b)
{
    if(a.c==b.c)
    {
       return a.lett<b.lett;
    }
    return a.c>b.c;
}
int main()
{
   char a;
   letters counts[40];
   for(int i=0;i<40;i++)
   {
       counts[i].c=0;
       counts[i].lett=i;
   }
   do
   {
       cin>>a;
       if(IsLetter(a))
       {
           counts[Which(a)].c++;
       }
   }while(a!='#');
   sort(counts,counts+39,Sort);
   for(int i=0;i<6;i++)
   {
       if(counts[i].c!=0)
       {
           cout<<char('A'+counts[i].lett);
       }
       else
       {
           break;
       }
   }
   cout<<"\n";
   return 0;
}
