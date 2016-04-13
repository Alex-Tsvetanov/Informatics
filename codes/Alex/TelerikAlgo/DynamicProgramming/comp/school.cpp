#include <iostream>
#include <vector>
#include <string>
#include <list>
 
#include <limits> // for numeric_limits
 
#include <set>
#include <utility> // for pair
#include <algorithm>
#include <iterator>
 
 
typedef int vertex_t;
typedef int weight_t;
 
const weight_t max_weight = std::numeric_limits<int>::max();
 
struct neighbor {
    vertex_t target;
    weight_t weight;
    neighbor(vertex_t arg_target, weight_t arg_weight)
        : target(arg_target), weight(arg_weight) { }
};
 
typedef std::vector<std::vector<neighbor> > adjacency_list_t;
 
 
void DijkstraComputePaths(vertex_t source,
                          const adjacency_list_t &adjacency_list,
                          std::vector<weight_t> &min_distance,
                          std::vector<vertex_t> &previous)
{
    int n = adjacency_list.size();
    min_distance.clear();
    min_distance.resize(n, max_weight);
    min_distance[source] = 0;
    previous.clear();
    previous.resize(n, -1);
    std::set<std::pair<weight_t, vertex_t> > vertex_queue;
    vertex_queue.insert(std::make_pair(min_distance[source], source));
 
    while (!vertex_queue.empty()) 
    {
        weight_t dist = vertex_queue.begin()->first;
        vertex_t u = vertex_queue.begin()->second;
        vertex_queue.erase(vertex_queue.begin());
 
        // Visit each edge exiting u
	const std::vector<neighbor> &neighbors = adjacency_list[u];
        for (std::vector<neighbor>::const_iterator neighbor_iter = neighbors.begin();
             neighbor_iter != neighbors.end();
             neighbor_iter++)
        {
            vertex_t v = neighbor_iter->target;
            weight_t weight = neighbor_iter->weight;
            weight_t distance_through_u = dist + weight;
	    if (distance_through_u < min_distance[v]) {
	        vertex_queue.erase(std::make_pair(min_distance[v], v));
 
	        min_distance[v] = distance_through_u;
	        previous[v] = u;
	        vertex_queue.insert(std::make_pair(min_distance[v], v));
 
	    }
 
        }
    }
}
 
std::list<vertex_t> DijkstraGetShortestPathTo(
    vertex_t vertex, const std::vector<vertex_t> &previous)
{
    std::list<vertex_t> path;
    for ( ; vertex != -1; vertex = previous[vertex])
        path.push_front(vertex);
    return path;
}
 
 
int main()
{
    int n, m, x, y;
    std::cin >> n >> m >> x >> y;

    x--;
    y--;
    std::vector < std::pair < int, std::pair < int, int > > > edges;

    int Max = std::numeric_limits<int>::min ();

    for (int i = 0 ; i < m ; i ++)
    {
	int a, b, c;
	std::cin >> a >> b >> c;
	a --;
	b --;
	edges.push_back ({a, {b, c}});
	Max = std::max (Max, c);
    }

    adjacency_list_t adjacency_list (n);

    for (int i = 0 ; i < m ; i ++)
    {
       adjacency_list [edges [i].first].push_back (neighbor(edges [i].second.first, Max - edges [i].second.second));
    }
    
    std::vector<weight_t> min_distance;
    std::vector<vertex_t> previous;
    DijkstraComputePaths(x, adjacency_list, min_distance, previous);
    auto X = DijkstraGetShortestPathTo (y, previous);
    std::cout << (X.size () - 1) * Max - min_distance[y] << std::endl;
    return 0;
}
