#include <iostream>

#include <cmath>

using namespace std;

int main(){

char c,v;

long long b1=0,b2=0,b3=0,k=0;

while(c!='.')
{
    b3++;

    cin>>c;v=c;

  if(c==v&&b3>1){b2++;v=c;}

  else v=c;

    if(c>='a'&&c<='z')b1++;

}

cout<<fabs(b1-(b2/2+2))<<endl;

return 0;
}
