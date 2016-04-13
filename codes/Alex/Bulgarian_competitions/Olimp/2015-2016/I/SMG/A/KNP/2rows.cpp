#include<iostream>
#include<map>
int main()
{
    for(int j=0; j<5; ++j){
    std::map<int, int> pos;
    int N;
    std::cin>>N;
    for(int i=0; i<N; ++i)
    {
        int a;
        std::cin>>a;
        pos[a] = i+1;
    }
    int curr=0;
    std::cin>>N;
    bool flag = true;
    for(int i=0; i<N; ++i)
    {
        int a;
        std::cin>>a;
        if(pos[a]&&flag)
        {
            if(curr>pos[a]) flag=false;
            else curr=pos[a];
        }
    }
    std::cout<<flag;
    }
    std::cout<<'\n';
}
