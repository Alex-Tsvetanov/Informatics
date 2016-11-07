#include <iostream>
#include<queue>
#define maxVertex 200000
#define maxTowns 400000
using namespace std;
struct vertex
{
    int from, to, weight;

};
bool operator<(vertex a, vertex b)
{
    return a.weight>b.weight;
}
priority_queue<vertex> dij;
vertex graph[maxTowns*2];
vertex vertexes[maxVertex];
bool visited[maxTowns];
int weight[maxTowns];
void dijkstra(int vertexCount)
{
    while(true)
    {
        int dijSize = dij.size();
        vertex teq[vertexCount];
        for(int l =0; l<dijSize; l++){
            teq[l] = dij.top();
            dij.pop();
        }
        for(int l =0; l<dijSize; l++)
        {
            vertex onova = teq[l];
            if(!visited[onova.to])
            {
                weight[onova.to] = weight[onova.from] + onova.weight;
                for(int i = 0; i<vertexCount; i++)
                    if(graph[i].from == onova.to)
                        dij.push(graph[i]);
            }
            visited[onova.from] = true;
        }
        if(dij.empty())
        break;
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int townsCount, fromTown, toTown, vertexCount = 0;
    cin>>townsCount>>fromTown>>toTown;
    int n;
    for(int i = 1; i<=townsCount; i++)
    {
        weight[i] = maxVertex;
        visited[i] = false;
    }
    while(cin)
    {
        vertex current;
        int from, to;
        cin>>current.from>>current.to;
        if(!cin)
            break;
        current.weight = 0;
        graph[vertexCount]=current;
        swap(current.from,current.to);
        current.weight = 1;
        graph[vertexCount+1]=current;
        vertexCount+=2;
    }
    visited[fromTown] = true;
    weight[fromTown] = 0;
    for(int i = 0; i<vertexCount; i++)
    {
        if(graph[i].from == fromTown)
        dij.push(graph[i]);
    }
    dijkstra(vertexCount);
    if(weight[toTown]==maxVertex)
    cout<<"X"<<endl;
    else cout<<weight[toTown]<<endl;
    return 0;
}

