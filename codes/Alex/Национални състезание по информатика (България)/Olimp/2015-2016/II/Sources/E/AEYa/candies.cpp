#include <iostream>
using namespace std;
int main () {
int a;
int j=0;
int y=0;
int h=0;
int b;
int c;
cin>>a>>b>>c;
while(a>0&&b>0&&c>0) {
a--;
b--;
c--;
h++;
j++;
y++;
}
if (a<=0||b<=0||c<=0) {
cout<<h+j+y-2<<endl;
}
return 0;
}

