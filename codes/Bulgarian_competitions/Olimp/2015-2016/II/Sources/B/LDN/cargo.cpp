#include<iostream>
#include<algorithm>

int main()
{
    int n, m, p;
    std::cin>>n>>m>>p;
    std::pair <int, int> date[m];
    bool possible=false;
    for(int i=0;i<m;i++)
    {
        std::cin>>date[i].first>>date[i].second;
        if(date[i].first%7>=1 and date[i].second%7<=5)
        {
            possible=true;
        }
    }

    if(m*(p/2)>n or p==1)
    {
        std::cout<<"IMPOSSIBLE"<<std::endl;
        return 0;
    }else
    {
        if(possible)
        {
            std::cout<<"OK"<<std::endl;
            return 0;
        }
    }
    std::cout<<"MIXED"<<std::endl;
}
