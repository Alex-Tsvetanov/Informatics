//Task: candies
//Author: Kinka Kirilova-Lupanova
#include <iostream>
using namespace std;

int main()
{int a, b, c, k;
 cin>>a>>b>>c;
 k=a;
 if (k>b/2) k=b/2;
 if (k>c) k=c;
 a=a- k;
 b=b-2 * k;
 c=c- k;
 if (a == 0) cout<<4 * k<<endl;
 else  
       if (b == 0) cout<<4 * k + 1<<endl;
       else 
            if (c == 0) cout<<4 * k + 2<<endl;
            else cout<<4 * k + 3<<endl;
return 0;
}                       

