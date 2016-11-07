#include <iostream>
using namespace std;

int main()
{
    int A=0,B=0,C=0,broqch=0;
    cin>>A>>B>>C;
    while (A!=0)
    {
      A=A-1;
      B=B-1;
      if (A!=0 && B!=0) broqch=broqch+2;
      else if (A!=0) broqch=broqch+1;
      while (C!=0)
      {
          C=C-1;
          B=B-1;
          if (C!=0 && B!=0) broqch=broqch+2;
          else if (C!=0) broqch=broqch+1;
      }  
    }
    cout<<broqch<<endl;
    
 return 0;
}