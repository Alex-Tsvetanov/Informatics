#include<stdio.h>
#include<math.h>
double sqr(double a){
    return a*a;
}
struct pt{
public:
int x,y;
double dist(pt a){
    return sqrt(sqr(a.x-x)+sqr(a.y-y));
}
}A[2000];
struct ang{
int a;
int b;
double cos;
}angs[1998];
double cos(double a,double b,double c){
return (sqr(a)+sqr(b)-sqr(c))/a*b;
}
int nang;
int N;
bool sth(double a,double b,double c, double d, double e){
    return (((int)((sqr(a)+sqr(b)-sqr(e))*d*c))-((int)((sqr(d)+sqr(c)-sqr(e))*a*b))) == 0;
}
int main(){
nang=0;
scanf("%d",&N);
N++;
int i,j;
for(i=0;i<N;i++){
  int x,y;
  scanf("%d%d",&x,&y);
  A[i].x=x;
  A[i].y=y;
}
for(i=1;i<N;i++){
    for(j=i+1;j<N;j++){
        bool yes=true;
        for(int f=1;f<N;f++){
            if(f!=i&&f!=j){
                yes=yes&&sth(A[0].dist(A[i]),A[0].dist(A[j]),A[f].dist(A[j]),A[f].dist(A[i]),A[i].dist(A[j]));
            }
        }
        if(yes){
                printf("1");
            angs[nang].a=i;
            angs[nang].b=j;
            angs[nang].cos=cos(A[0].dist(A[i]),A[0].dist(A[j]),A[i].dist(A[j]));
            j=N;
            nang++;
        }
    }
}
for(i=0;i<nang;i++){
    int sm=i;
    for(j=i+1;j<nang;j++){
        if(angs[j].cos>angs[sm].cos){
            sm=j;
        }
        if((int)(angs[i].cos*100000)==(int)(angs[sm].cos*100000)){
            if(angs[i].a<angs[sm].a){
                sm=i;
            }
        }
    }
    ang a=angs[i];
    angs[i]=angs[sm];
    angs[sm]=a;
}
for(i=0;i<nang-1;i++){
    printf("%d %d\n",angs[i].a,angs[i].b);
}
printf("%d %d",angs[i].a,angs[i].b);
}
/*
4
0 0
1 0
1 1
0 1
-1 0*/
