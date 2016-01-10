//Task: matches
//Author: Kinka Kirilova-Lupanova
#include <iostream>
using namespace std;

int main()
{long long a, b, c, d;
 cin>>a>>b>>c>>d;
 if (a == b && c == d) cout<<"YES"<<endl<<a*c<<endl;
 else if (a == c && b == d) cout<<"YES"<<endl<<a*b<<endl;
      else if (a == d && b == c) cout<<"YES"<<endl<<a*b<<endl;
           else cout<<"NO"<<endl<<a+b+c+d<<endl;
 return 0;
}



