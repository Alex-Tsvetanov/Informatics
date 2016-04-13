#include<iostream>
#include<vector>
#include<utility>
#define INFINITY 999
 
using namespace std;
 
class Dijkstra{
    private:
        static const int n = 500;
        int adjMatrix[n][n];
        int predecessor[n],distance[n];
        bool mark[n]; //keep track of visited node
        int source;
        int numOfVertices;
    public:
        void read();
        void initialize();
        int getClosestUnmarkedNode();
        void calculateDistance();
        void output();
        void printPath(int);
};
 
int End;
void Dijkstra::read(){
    cin>>numOfVertices;
    int edges;
    cin >> edges;
    cin>>source >> End;
    source --;
    End --;
    vector < pair < int, pair < int, int > > > ln (edges);//numOfVertices);
    int Max = -1;
    for (int i = 0 ; i < edges ; i ++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        a --;
        b --;
        ln.push_back ({a, {b, c}});
        Max = max  (Max, c);
    }
    for (int i = 0 ; i < numOfVertices ; i ++)
        for (int j = 0 ; j < numOfVertices ; j ++)
            adjMatrix [i][j] = INFINITY;
    for (int i = 0 ; i < edges ; i ++)
    {
        adjMatrix [ln [i].first][ln [i].second.first] = Max - ln [i].second.second;
    }
}
 
 
void Dijkstra::initialize(){
    for(int i=0;i<numOfVertices;i++) {
        mark[i] = false;
        predecessor[i] = -1;
        distance[i] = INFINITY;
    }
    distance[source]= 0;
}
 
 
int Dijkstra::getClosestUnmarkedNode(){
    int minDistance = INFINITY;
    int closestUnmarkedNode;
    for(int i=0;i<numOfVertices;i++) {
        if((!mark[i]) && ( minDistance >= distance[i])) {
            minDistance = distance[i];
            closestUnmarkedNode = i;
        }
    }
    return closestUnmarkedNode;
}
 
 
void Dijkstra::calculateDistance(){
    initialize();
    int minDistance = INFINITY;
    int closestUnmarkedNode;
    int count = 0;
    while(count < numOfVertices) {
        closestUnmarkedNode = getClosestUnmarkedNode();
        mark[closestUnmarkedNode] = true;
        for(int i=0;i<numOfVertices;i++) {
            if((!mark[i]) && (adjMatrix[closestUnmarkedNode][i]>0) ) {
                if(distance[i] > distance[closestUnmarkedNode]+adjMatrix[closestUnmarkedNode][i]) {
                    distance[i] = distance[closestUnmarkedNode]+adjMatrix[closestUnmarkedNode][i];
                    predecessor[i] = closestUnmarkedNode;
                }
            }
        }
        count++;
    }
}
 
 
void Dijkstra::printPath(int node){
    if(node == source)
        cout<<(char)(node + 97)<<"..";
    else if(predecessor[node] == -1)
        cout<<"No path from "<<source<<"to "<<(char)(node + 97)<<endl;
    else {
        printPath(predecessor[node]);
        cout<<(char) (node + 97)<<"..";
    }
}
 
 
void Dijkstra::output(){
    for(int i=0;i<numOfVertices;i++) {
        if(i == source)
            cout<<(char)(source + 97)<<".."<<source;
        else
            printPath(i);
        cout<<"->"<<distance[i]<<endl;
    }
    cout << distance [End];
}
 
 
int main(){
    Dijkstra G;
    G.read();
    G.calculateDistance();
    G.output();
    return 0;
}
