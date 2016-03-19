#include<iostream>
#include<vector>
#define MAXM 1000000
using namespace std;
int n, m, p, flag1, flag2, br=0;
//flag1=0-impossible; flag2=1-mixed
int z[MAXM][2];
vector <int> vec;
void sort_z(){
	int temp;
	for(int i=0; i<m-1; i++){
		for(int j=i+1; j<m; j++){
			if(z[i][0]>z[j][0]){
				temp=z[i][0];
				z[i][0]=z[j][0];
				z[j][0]=temp;
				temp=z[i][1];
				z[i][1]=z[j][1];
				z[j][1]=temp;
			}
		}	
	}
	
}
int main(){
	cin>>n>>m>>p;
	vec.resize(n+1);
	for(int i=0; i<m; i++){
		cin>>z[i][0]>>z[i][1];
	}
	p=p/2;
	flag1=0;
	flag2=0;
	sort_z();
/*	for(int i=0; i<m; i++){
		cout<<z[i][0]<<" "<<z[i][1]<<endl;
	}*/
	for(int i=0; i<m; i++){
		for(int j=z[i][0]; j<=z[i][1]; j++){
			//cout<<"j= "<<j<<endl;
			if(j%6!=0 && j%7!=0 && vec[j]<p) {
				vec[j]++;
				flag1++;
				//cout<<"1. vec["<<j<<"]= "<<vec[j]<<endl;
				break;
			}
			else if(j%6==0 && j+2<=z[i][1] && vec[j+2]<p){
				vec[j+2]++;
				flag1++;
				//cout<<"2. vec["<<j+2<<"]= "<<vec[j+2]<<endl;
				break;
			}
			else if(j%7==0 && j+1<=z[i][1] && vec[j+1]<p){
				vec[j+1]++;
				flag1++;
				//cout<<"3. vec["<<j+1<<"]= "<<vec[j+1]<<endl;
				break;
			}
			else if(vec[j]<p){
				vec[j]++;
				flag2++;
				br++;
				//cout<<"4. vec["<<j<<"]= "<<vec[j]<<endl;
				break;
			}
		}
		
	}
	//cout<<flag1<<" "<<flag2<<endl;
	if(flag1+flag2<m){
			cout<<"IMPOSSIBLE"<<endl;
			return 0;
		}
	else if(flag2>0){
			cout<<"MIXED"<<endl;
			return 0;
		}
	else if(flag1>0 && flag2==0){
			cout<<"OK"<<endl;
			return 0;
		}
}
