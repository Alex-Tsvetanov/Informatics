#include<iostream>
#include<cmath>
const int MAXC = 10000;
const int MAXP = 10;
struct circle
{
    int x, y, r;
    void adj(int x, int y, int r)
    {
        this->x = x;
        this->y = y;
        this->r = r;
    }
};
double length(const circle a, const circle b)
{
    return std::sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
circle C[MAXC], P[MAXP];
int S[MAXC];
int N, M, Q;
void input()
{
    std::cin>>N>>M>>Q;
    for(int i=0; i<N; ++i)
    {
        int x, y, z;
        std::cin>>x>>y>>z;
        C[i].adj(x, y, z);
    }
    for(int i=0; i<M; ++i)
    {
        int x, y;
        std::cin>>x>>y;
        P[i].adj(x, y, 0);
    }
    for(int i=0; i<Q; ++i)
        std::cin>>S[i];
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    input();
    long long res=0; ///max 4*10000*10*10000
    int turn_res = 1;
    for(int s=0; s<Q; ++s)
    {
        int rad = S[s]*(1<<(!(turn_res%2||(turn_res==0))));
        turn_res = 0;
        for(int m=0; m<M; ++m)
            for(int n=0; n<N; ++n)
                if(length(P[m], C[n])+C[n].r<=rad)
                {
                    //std::cout<<rad<<" "<<m<<" "<<n<<" "<<length(P[m], C[n])<<'\n';
                    ++turn_res;
                }
        res += turn_res;
    }
    std::cout<<res<<'\n';
    return 0;
}
