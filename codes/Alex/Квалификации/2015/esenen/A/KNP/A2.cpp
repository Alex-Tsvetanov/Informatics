#include<iostream>
#include<vector>
bool Na[10000][10000];
int  C[10000][10000];
const int INFINITY = 70000;
int F[10000];
int N;
void dfs(int i, int curr)
{
    for(int j=0; j<N; ++j)
        if(Na[i][j])
            Na[j][i] = false;
    for(int j=0; j<N; ++j)
    {
        if(Na[i][j])
        {
            int pass = std::min(curr, C[i][j]);
            F[j] = std::min(F[j], pass);
        }
        if(j!=N-1) dfs(j, F[j]);
    }
}
int main()
{
    int M;
    std::cin>>N>>M;
    for(int i=0; i<M; ++i)
    {
        int a, b, c;
        std::cin>>a>>b>>c;
        Na[a-1][b-1]=true;
        Na[b-1][a-1]=true;
        C[a-1][b-1] = c;
        C[b-1][a-1] = c;
        F[a-1] = INFINITY;
        F[b-1] = INFINITY;
    }
    dfs(0, F[0]);
    std::cout<<F[N-1]<<'\n';
    return 0;
}
