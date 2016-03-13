//Task:word
//Author:Teodosi Teodosiev
#include <iostream>
using namespace std;
int main()
{
  int counter[26]={0}, index[6]={0};char ch;
  do
  {
   cin.get(ch);
   if (ch>='a'&&ch<='z')counter[ch-'a']++;
   else if (ch>='A'&&ch<='Z')counter[ch-'A']++;
   }
  while (ch !='#');
  int i, max_ind;
  for (i=0;i<6;i++)
  {
   max_ind=0;
   for (int j=0;j<26;j++)
   if (counter[j]>counter[max_ind])max_ind=j;

   if(counter[max_ind]==0) break;
   counter[max_ind]=0;
   index[i]=max_ind;
  }
  for (int j=0;j<i;j++)
   cout<<(char)(index[j]+'A');
  cout<<endl;
}
