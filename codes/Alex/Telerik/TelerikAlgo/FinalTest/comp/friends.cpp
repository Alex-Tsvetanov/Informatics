#include <iostream>
#include <vector>
using namespace std;
	class Edge
	{
		public: int To;
		public: int Length;

		public: Edge(int to, int length)
		{
			this->To = to;
			this->Length = length;
		}
	};

	struct 
	{
		vector<Edge>* edges;
		int maxn;
		int* tree;
		int* mindist;

		void Main()
		{
			int line [3];
			int n;
			int m;
			cin >> n >> m;

			edges = new vector<Edge>[n];
			for(int i = 0; i < n; i++)
			{
				edges[i] = vector<Edge>();
			}

			mindist = new int[n];

			int start;
			int end;
			cin >> start >> end;
			start --;
			end --;

			int mid1;
			int mid2;
			cin >> mid1 >> mid2;
			mid1 --;
			mid2 --;

			for(int i = 0; i < m; i++)
			{
				cin >> line [0] >> line [1] >> line [2];
				edges[line[0] - 1].push_back(Edge(line[1] - 1, line[2]));
				edges[line[1] - 1].push_back(Edge(line[0] - 1, line[2]));
			}
			
			maxn = 1;
			while(maxn < n)
			{
				maxn *= 2;
			}

			tree = new int[maxn * 2];
			for(int i = 0; i < 2*maxn; i++)
			{
				tree[i] = -1;
			}

			// Dijkstras
			
			Dijkstra(mid1, mid2);
			int s1 = mindist[start];
			int e1 = mindist[end];
			int m12 = mindist[mid2];

			Dijkstra(mid2, mid1);
			int s2 = mindist[start];
			int e2 = mindist[end];
			//int m21 = mindist[mid1];
			
			cout << (min(s1 + m12 + e2, s2 + m12 + e1)) << "\n";
		}

		void Update(int index)
		{
			index += maxn;
			while(index > 1)
			{
				if(tree[index ^ 1] < 0)
				{
					tree[index / 2] = tree[index];
				}
				else if(tree[index] < 0)
				{
					tree[index / 2] = tree[index ^ 1];
				}
				else if(mindist[tree[index]] < mindist[tree[index ^ 1]])
				{
					tree[index / 2] = tree[index];
				}
				else
				{
					tree[index / 2] = tree[index ^ 1];
				}

				index /= 2;
			}
		}

		void Push(int index, int dist)
		{
			mindist[index] = dist;
			tree[index + maxn] = index;
			Update(index);
		}

		void Pop(int index)
		{
			tree[index + maxn] = -1;
			Update(index);
		}

		void Dijkstra(int from, int exclude)
		{
			for(int i = 0; i < sizeof(mindist)/sizeof(*mindist); i++)
			{
				mindist[i] = 1 << 30;
			}

			Push(from, 0);

			while(tree[1] >= 0)
			{
				from = tree[1];
				Pop(from);
				
				if(from == exclude)
				{
					continue;
				}

				for(auto& edge : edges[from])
				{
					int currdist = mindist[from] + edge.Length;
					if(mindist[edge.To] > currdist)
					{
						mindist[edge.To] = currdist;
						Push(edge.To, currdist);
					}
				}
			}
		}
	} StartUp;

int main ()
{
	StartUp.Main ();
}
