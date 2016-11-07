#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;
char word[100000];
int letter[30];
int main()
{
    int len;
    char vhod;
    for(len=0; vhod!='#'; len++)
    {
        vhod=cin.get();
        word[len]=vhod;
        if(word[len]>='A' and word[len]<='Z')
        {
            letter[word[len]-'A']++;
        }
        else
        {
            if(word[len]>='a' and word[len]<='z')
            {
                letter[word[len]-'a']++;
            }
        }
    }
    int t=0;
    for(int i=0; i<6; i++)
    {
        for(int j=0; j<26; j++)
        {
            if(letter[t]<letter[j])
            {
                t=j;
            }
        }
        if(letter[t]!=0)
        {
            cout<<char(t+'A');
        }
        letter[t]=0;
        t=0;
    }
    cout<<endl;
    return 0;
}
