/*#include<iostream>
#include<string>
using namespace std;
int main() {
	long long h1, m1, h2, m2;
	string a, b, c;
	cin >> a >> b;
	for (int i = 0;i <5;i++) {
		if (a[i] == ':') {
			a[i] = ' ';
		}if (b[i] == ':') {
			b[i] = ' ';
		}
	}
	h1 = a[0] * 10 + a[1];
	m1 = a[3] * 10 + a[4];
	if (b[0] == '0' and b[1] == '0') {
		b[0] == '2';
		b[1] == '4';
	}
	if (a[0] == '0' and a[1] == '0') {
		a[0] == '2';
		a[1] == '4';
	}
	h2 = b[0] * 10 + b[1];
	m2 = b[3] * 10 + b[4];
	if (h1 == 0)h1 = 24;	
	if (h2 == 0)h2 = 24;
	if (h1 < h2) {
		cout << h2 - h1 << ":" << m2 - m1;
	}
	else {
		cout << h1 - h2 << ":" << m1 - m2;
	}
	cout << endl;
	return 0;
}



21:13
00:07
*/