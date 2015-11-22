#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <fstream>
using namespace std;

 
void computeLPSArray(char *pat, int M, int *lps);
 
int KMPSearch(char *pat, char *txt)
{
   int ans  = 0;
    int M = strlen(pat);
    int N = strlen(txt);
 
    int *lps = (int *)malloc(sizeof(int)*M);
    int j  = 0;
 
    computeLPSArray(pat, M, lps);
 
    int i = 0;
    while (i < N)
    {
      if (pat[j] == txt[i])
      {
        j++;
        i++;
      }
 
      if (j == M)
      {
         ans ++;
        j = lps[j-1];
      }
 
      else if (i < N && pat[j] != txt[i])
      {
        if (j != 0)
         j = lps[j-1];
        else
         i = i+1;
      }
    }
    free(lps);
    return ans;
}
 
void computeLPSArray(char *pat, int M, int *lps)
{
    int len = 0;
    int i;
 
    lps[0] = 0;
    i = 1;
 
    while (i < M)
    {
       if (pat[i] == pat[len])
       {
         len++;
         lps[i] = len;
         i++;
       }
       else
       {
         if (len != 0)
         {
           len = lps[len-1];
         }
         else
         {
           lps[i] = 0;
           i++;
         }
       }
    }
}
 
char S [500000];
char pat [5000];

int main()
{
   ifstream fin ("clown.in");
   ofstream fout ("clown.out");
   fin >> S;
   int M;
   fin >> M;
   for (int i = 0 ; i < M ; i ++)
   {
      fin >> pat;
      fout << KMPSearch(pat, S) << "\n";
   }
   return 0;
}

