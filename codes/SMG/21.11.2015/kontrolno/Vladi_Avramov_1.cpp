#include <iostream>

using namespace std;

int chas1, chas3, chas4, min1, min2,min3,min4 chas2, n=0;
int masiv1[5], masiv[5];

int main(){
cin >> chas1 >> min1 >> chas2 >> min2;
cout << chas1 << ":" << min1 << endl << chas2 << ":" << min2 << endl;
chas3 = chas1;
min3 = min1;
chas4 = chas2;
min4 = min2;

for(int i = 0 ; i < 4 ; i++){
		if(n==0){masiv1[i] = chas3%10 ; chas3 = chas3/10;} 
		if(n==1){masiv[i] = min3%10 ; min3 = min3/10;}
}	

	for(int i = 0 ; i < 4 ; i++){
	cout << masiv[i];
}
	
return 0;
}
