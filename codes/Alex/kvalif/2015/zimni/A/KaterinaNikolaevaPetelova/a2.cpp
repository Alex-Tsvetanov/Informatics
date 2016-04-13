#include<iostream>
#include<cstdio>
#include<vector>
int main()
{
    int M, N;
    std::cin>>M>>N;
    std::vector<int> m, s;
    int a, b;
    for(int i=0; i<N; ++i){
    scanf("%d",&a);
    scanf("%d",&b);
    while(!m.empty())
    {
        if(m.back()<a)
        {
            m.push_back(a);
            m.push_back(b);
            while(!s.empty())
            {
                int sm1 = s.back(); s.pop_back();
                int sm2 = s.back(); s.pop_back();
                m.push_back(sm1);
                m.push_back(sm2);
            }
            break;
        }
        else
        {
            int sm1 = m.back(); m.pop_back();
            int sm2 = m.back(); m.pop_back();
            if(sm2 > a&& sm2 > b)
            {
                s.push_back(sm1);
                s.push_back(sm2);
            }
        }
    }
    if(m.empty())
    {
        m.push_back(a);
            m.push_back(b);
            while(!s.empty())
            {
                int sm1 = s.back(); s.pop_back();
                int sm2 = s.back(); s.pop_back();
                m.push_back(sm1);
                m.push_back(sm2);
            }
    }}
    std::cout<<m.size()/2<<'\n';
    return 0;
}
