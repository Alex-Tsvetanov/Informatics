#include<iostream>
#include<string.h>
using namespace std;

bool CheckIfPalindrome(char niz[10000])
{
    int i = 0;
    int j = strlen(niz) - 1;
    while (i < j)
    {
        if (niz[i] != niz[j])
        {
            return false;
        }
        i++;
        j--;
    }
    return true;
}

void AddSpace(char  niz[10000], int a)
{
    int n=strlen(niz);
    for(int i=n; i>=a; i--)
    {
            niz[i+1]=niz[i];
    }
    niz[a]=' ';


}

void CreateArrays(char niz[10000],int a, char mass1 [10000], char mass2 [10000])
{
    int br=0;
    int i=0;
    while(niz[i]!=' ')
    {
        mass1[i]=niz[i];
        i++;
    }
    int j=i+1;
    int t=0;
    while(j!=strlen(niz))
    {
        mass2[t]=niz[j];
        j++;
        t++;
    }

}

int main ()
{
        char niz[10000];
        cin>>niz;
        int a=2;
        char mass1 [10000];
        char mass2 [10000];
        int br=0;
        bool flag1, flag2;
        if(CheckIfPalindrome(niz)==true)cout<<0;
        if(CheckIfPalindrome(niz)==false)
        {
            AddSpace(niz,a);
            CreateArrays(niz, a, mass1, mass2);
        br++;
           if(CheckIfPalindrome(mass1)==true)
            {
                if(CheckIfPalindrome(mass2)==true)cout<<br;
            }
        }


    return 0;

}
