#include <iostream>
#include <string>
using namespace std;
int x,a,b;
string s;
char c;

int StrToInt ( string ss){
int p=0,i,d;
	d=ss.size();
	for (i=0;i<d;i++){
		p=p*10+(ss[i]-'0');
	}
return p;	
}

int main() {
int d,px,pz,pr;

	cin>>s;
	d=s.size();
	px=s.find('X');
	pz=s.find('+');
	pr=s.find('=');
	b=StrToInt(s.substr(pr+1,d-pr));
	if (px<pz) 
	a=StrToInt(s.substr(pz+1,pr-pz-1));
	else
	a=StrToInt(s.substr(0,pz));
	cout<<b-a<<endl;
	return 0;
}
/*

*/
