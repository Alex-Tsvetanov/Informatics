/* fopen example */
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

fstream fs;

int a[10001],n,M;
int a1, a2;
bool fl;
int Toc;
string s;

bool Prow () {
bool ff=true;
int i;
	for (i=1; i<=n; i++) 
		if (a[i]!=i) {
			ff=false;
			break;
		}
	return ff;
}

int main (int argc, char *argv[])
{
int i,ii=0;	
// *.in
// вход
	fl=true;
  fs.open (argv[1], fstream::in);
//  fs.open ("swap.07.in", fstream::in );
  if (fs.is_open())
  {
    fs >>n;
    for (i=1;i<=n; i++) fs>>a[i];
    fs.close();
  }
  else
  {
    cout<<"0\nError opening file 1\n";
    return 0;
  }
// изход
  fs.open (argv[3], fstream::in);
//  fs.open ("swap.07.out", fstream::in | fstream::out | fstream::app);
    if (fs.is_open())
  {
	fs>>M;
	for (i=1; i<=M;i++) {
		fs>>a1>>a2;	
		if (a1==a[a1] || a2==a[a2]) {
			cout<<0<<endl;
			cout<<"Mesti element a[i] kojto e na mjasto i";
			return 0;
		}
		else
		if (abs(a1-a2)!=1) {
			cout<<0<<endl;
			cout<<"ne sa sysedni elementi: abs(i- j) !=1";
			return 0;
		}
		else
		if (a1<0 || a1>n || a2<0 || a2>n) {
			cout<<0<<endl;
			cout<<"i,j izwyn [1,N]";
			return 0;
		}	
		swap(a[a1],a[a2]);
	}
    fs.close();
  }
  else
  {
    cout << "0\nError opening file 3\n";
    return 0;
  }
  if (Prow ()) {
	cout<<1<<endl;
	cout<<"OK";
  }
  else {
  	cout<<0<<endl;
  	cout<<"Nepodredeni";
  }
  
	
  return 0;
}
