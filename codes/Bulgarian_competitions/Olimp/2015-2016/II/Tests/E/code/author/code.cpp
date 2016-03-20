//Task: code
//Author: Emil Kelevedjiev
#include<iostream>
using namespace std;

int main()
{
    char s;
    cin >> s;
    char p=s;
    int c=1;
    int d=0;
    int t=1;
    while(1)
    {
      cin >> s;
      if(s!='.') c++;
      if(s==p) t++;
      else
      {
        if(t==1) d = d + 1;
        else if(t<10) d = d + 2;
        else if(t<100) d = d + 3;
        else if(t<1000) d = d + 4;
        else if(t<10000) d = d + 5;
        else if(t<100000) d = d + 6;
        else if(t<1000000) d = d + 7;
        else if(t<10000000) d = d + 8;
        if(s=='.') break;
        t=1;
        p=s;
      }
    }
    cout << c-d << endl;
}
