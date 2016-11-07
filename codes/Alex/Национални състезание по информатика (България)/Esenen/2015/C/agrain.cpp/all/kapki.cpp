#include<iostream>
#include<set>
using namespace std;
long long n,l,d,x1,a,b,masiv[10000003],otg;
set<long long>S;
int main(){
	cin>>n>>l>>d>>x1>>a>>b;
	S.insert(-1);
	S.insert(l+1);
	masiv[0]=x1;
	S.insert(masiv[0]);
	for(long long i=1;i<n;i++){
		masiv[i]=(masiv[i-1]*a+b)%(l+1);
		S.insert(masiv[i]);
	}
	/*for(long long i=1;i<n;i++){
	  cout<<masiv[i]<<" ";
	  }*/
	for(long long i=n-1;i>=0;i=i-1){
		otg=i;
		set<long long>::iterator u=S.upper_bound(masiv[i]);
		set<long long>::iterator l=S.lower_bound(masiv[i]);
		l--;
		//cout<<*u<<" "<<*l<<"\n";
		if((*u-*l)>d){
			if((*u-*S.find(masiv[i]))>d or (*S.find(masiv[i])-*l)>d){
				otg=-2;
			}
			break;
		}
		S.erase(masiv[i]);
	}
	cout<<otg+1;
	return 0;
}
//KN K3             K1         K2 KK
