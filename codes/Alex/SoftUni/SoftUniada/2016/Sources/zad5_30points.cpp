#include<iostream>
#include<cmath>
using namespace std;
struct dot{
	double x,y;
};
bool tri(double a,double b,double c){
	return (a>=b && b>=c) || (a<=b && b<=c);
}
int cross(){
	dot rec[4],cir;
	double r;
	char ju;
	for(int i=0;i<2;i++){
		cin>>ju;
		if(ju=='c'){
			for(int i=0;i<6;i++)cin>>ju;
			cin>>cir.x>>ju>>cir.y>>ju>>r>>ju;
		}else{
			for(int i=0;i<9;i++)cin>>ju;
			cin>>rec[0].x>>ju;
			cin>>rec[0].y>>ju;
			cin>>rec[2].x>>ju;
			cin>>rec[2].y>>ju;
			rec[1].y=rec[0].y;
			rec[1].x=rec[2].x;
			rec[3].y=rec[2].y;
			rec[3].x=rec[0].x;
		}
	}
	bool in[4];
	double d[4];
	int hin=0;
	for(int i=0;i<4;i++){
		in[i]=sqrt((rec[i].x-cir.x)*(rec[i].x-cir.x)+(rec[i].y-cir.y)*(rec[i].y-cir.y))<=r;
		if(i%2==0)  d[i]=cir.x-rec[i].x;
		else d[i]=cir.y-rec[i].y;
		hin+=in[i];
	}
	if(hin==4){
		cout<<"Rectangle inside circle";
		return 0;
	}
	if(hin>0){
		cout<<"Rectangle and circle cross";
		return 0;
	}
	if(rec[0].x<=cir.x-r && rec[2].x>=cir.x+r && rec[0].y>=cir.y+r && rec[2].y<=cir.y-r){
		cout<<"Circle inside rectangle";
		return 0;
	}
	if(tri(rec[0].x,cir.x+r,rec[2].x) || tri(rec[0].x,cir.x-r,rec[2].x) || tri(rec[0].y,cir.y+r,rec[2].y) || tri(rec[0].y,cir.y-r,rec[2].y)){
		cout<<"Rectangle and circle cross";
		return 0;
	}
	cout<<"Rectangle and circle do not cross";
	return 0;
}
int main(){
	int m;
	cin>>m;
	for(int i=0;i<m;i++){
		cross();
		cout<<endl;
	}
}
