#include<iostream>
#include<iomanip>
int main()
{
    int a, b;
    std::cin>>a>>b;
    if(a>b) std::swap(a,b);
    if(a==b) std::cout<<std::fixed<<std::setprecision(3)<<a*b*1.25<<'\n';
    else if(!(b%a)) std::cout<<std::fixed<<std::setprecision(3)<<2*a*b-a*a<<'\n';
    else std::cout<<std::fixed<<std::setprecision(3)<<2*a*b-a*(b/2)-((a/3)+a)*(b/2)<<'\n';
    return 0;
}
