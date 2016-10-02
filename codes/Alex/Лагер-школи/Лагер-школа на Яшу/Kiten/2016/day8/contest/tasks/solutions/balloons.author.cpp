#include<iostream>
using namespace std;
int main()
{
	int n,m;
	float price;
	int broj[6], maxcena[6],p;
	cin>>n>>m;
	char c;
	for (int i=0; i<6; i++) {broj[i]=0;maxcena[i]=0;}
	for (int i=0; i<n;i++){
        cin >>c; 
        switch (c){
        case 'y': broj[0]++;break;
        case 'w': broj[1]++;break;
        case 'g': broj[2]++;break;
        case 'r': broj[3]++;break;
        case 'p': broj[4]++;break;
        case 'b': broj[5]++;break;
        }
   }
    for (int i=0; i<m; i++){
    cin>>c>>p;
   switch (c){
        case 'y': if (maxcena[0]<p) maxcena[0]=p;break;
        case 'w': if (maxcena[1]<p) maxcena[1]=p;break;
        case 'g': if (maxcena[2]<p) maxcena[2]=p;break;
        case 'r': if (maxcena[3]<p) maxcena[3]=p;break;
        case 'p': if (maxcena[4]<p) maxcena[4]=p;break;
        case 'b': if (maxcena[5]<p) maxcena[5]=p;break;
        }
    }
    p=0;
	for (int i=0; i<6; i++)
	    p=p+broj[i]*maxcena[i];
	price= (float) p/100;
	printf("%4.2f\n",price);    
	return 0;
}
