#include<iostream>
#include<cmath>
struct point{int x, y;};
point P[7];
double len(int a1, int a2)
{
    return (P[a1].x-P[a2].x)*(P[a1].x-P[a2].x) + (P[a1].y-P[a2].y)*(P[a1].y-P[a2].y);
}
double cos(int a1, int a2, int a3)
{
    double l1 = len(a1, a2), l2 = len(a3, a2), l3 = len(a1, a3);
    return (l1+l2-l3)/(2*std::sqrt(l1*l2));
}
double S(int a1, int a2)
{
    return std::acos(cos(a1,0,a2))/2;
}
int main()
{
    for(int i=0; i<7; ++i)
        std::cin>>P[i].x>>P[i].y;
    double res=S(1,2)+S(3,4)+S(5,6);
    if(res>=M_PI) std::cout<<100<<'\n';
    else          std::cout<<(res/M_PI)*100<<'\n';
    return 0;
}
