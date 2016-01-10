//Task: sum
//Author: Pavel Petrov

#include <iostream>
using namespace std;
int e1,d1,s1,e2,d2,s2;
char c;
int main() {
	cin>>c;
	s1=c-'0';
	cin>>c;
	d1=c-'0';
	cin>>c;
	e1=c-'0';
	cin>>c;
	cin>>c;
	s2=c-'0';
	cin>>c;
	d2=c-'0';
	cin>>c;
	e2=c-'0';
	cout<<s1+s2<<(d1+d2)%10<<(e1+e2)%10<<endl;
	cout<<100*(s1+s2)+10*(d1+d2)+e1+e2<<endl;
	return 0;
}

