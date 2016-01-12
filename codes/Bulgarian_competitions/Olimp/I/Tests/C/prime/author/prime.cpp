#include<iostream>

using namespace std;

int main()
{
 int d,p=3;
 long nr=0;
 char c;

 cin.get(c);
 nr=2*(c-'0');
 do
    {cin.get(c);
     if (c!='\n')
        {nr += (c-'0')*p;
         do
          {
            p+=2;
            for (d=3; p%d && d*d<=p; d+=2);
           }
         while (d*d<=p);
        }
   }
 while (c!='\n');

 cout<<nr<<'\n';

 return 0;
}
