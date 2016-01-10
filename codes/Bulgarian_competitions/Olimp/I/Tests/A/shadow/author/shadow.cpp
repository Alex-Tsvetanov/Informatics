#include <iostream>
#include <cmath>
#include <algorithm>
#define EPS 0.0000000001
using namespace std;
typedef struct {double x,y;} Point;
double a,b;
Point Rect[4],Rect1[4];
double Rad,eps=0.0001,S1,S2,alpha,beta,pi=4*atan(1);

bool eq(double a,double b,double eps)
{return fabs(a-b)<eps;
}
double det(double a,double b,double c,double d)
{return a*d-b*c;
}
int Intersect(Point A,Point B,Point C,Point D,Point *X)
{double a1,b1,c1,a2,b2,c2,t;
 a1=det(1,B.y,1,A.y);
 b1=det(B.x,1,A.x,1);
 c1=det(A.x,A.y,B.x,B.y);
 a2=det(1,D.y,1,C.y);
 b2=det(D.x,1,C.x,1);
 c2=det(C.x,C.y,D.x,D.y);
 t=det(a1,a2,b1,b2);
 if (eq(t,0,EPS)) return eq(c1,c2,EPS)?2:1;
 X->x=det(b1,b2,c1,c2)/t;
 X->y=det(c1,c2,a1,a2)/t;
 return 0;
}
double Area(Point A, Point B, Point C)
{return 0.5*fabs((B.x-A.x)*(C.y-A.y)-(C.x-A.x)*(B.y-A.y));
}
void inp(void)
{cin>>a>>b;
 if (a>b) swap(a,b);
 S1=2*a*b-a*a;
 Rad=sqrt(a*a+b*b)/2;
 alpha=atan(b/a);
 beta=pi-alpha;
 Rect[0].x=a/2;
 Rect[0].y=b/2;
 Rect[1].x=-a/2;
 Rect[1].y=b/2;
 Rect[2].x=-a/2;
 Rect[2].y=-b/2;
 Rect[3].x=a/2;
 Rect[3].y=-b/2;
}
double calc(double phi)
{Point P,Q,R,S;
 Rect1[0].x=Rad*cos(phi);
 Rect1[0].y=Rad*sin(phi);
 Rect1[1].x=Rad*cos(phi+pi-2*alpha);
 Rect1[1].y=Rad*sin(phi+pi-2*alpha);
 Rect1[2].x=-Rect1[0].x;
 Rect1[2].y=-Rect1[0].y;
 Rect1[3].x=-Rect1[1].x;
 Rect1[3].y=-Rect1[1].y;
 Intersect (Rect1[0],Rect1[1],Rect[0],Rect[1],&P);
 Intersect (Rect1[0],Rect1[3],Rect[0],Rect[1],&Q);
 Intersect (Rect1[0],Rect1[1],Rect[1],Rect[2],&R);
 Intersect (Rect1[1],Rect1[2],Rect[1],Rect[2],&S);
 return a*b+2*(Area(Rect1[0],P,Q)+Area(Rect1[1],R,S));
}
double solve()
{double start=alpha,end=beta,st=(beta-alpha)/10;
 double s,ps=a*b,phi;
 do
 {if (eq(start,end,EPS)) return calc(start);
  phi=start;
  do
  {phi+=st;
   s=calc(phi);
   if (s<ps) break;
   ps=s;
  }while (phi<=end);
  if (eq(s,ps,eps)) return s;
  start=max(phi-2*st,alpha);
  end=min(beta,phi+st);
  ps=calc(start);
  st/=10;
 }while (true);
}

int main(void)
{inp();
 S2=solve();
 cout.precision(3);
 cout<<fixed<<max(S1,S2)<<endl;
 return 0;
}
