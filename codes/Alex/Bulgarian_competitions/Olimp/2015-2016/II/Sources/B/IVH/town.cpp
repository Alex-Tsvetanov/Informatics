
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int numerr=0;
const int MAXM = 200000;
vector <int> A[2*MAXM];
vector <int> B[2*MAXM];
int n, a,b;
int used[2*MAXM];
int level=1;
int levelbfs=0;
int levelEnd, nodetemp;
void BFS(int node)
{
	queue<int> q;
	q.push(node);
	levelEnd=node;
	used[node] = level;

              level++;
	while(!q.empty())
	{
		node = q.front();
		q.pop();

		for(int i = 0; i < A[node].size(); i++)
		{
            	if(!used[A[node][i]]&&(B[node][i]!=0))
			{


			used[A[node][i]] = numerr;

			q.push(A[node][i]);nodetemp=A[node][i];
			}
		}
       }
	}

void BFS1(int node)
{
	queue<int> q;
	q.push(node);

	used[node] = n+1;


	while(!q.empty())
	{
		node = q.front();
		q.pop();

		for(int i = 0; i < A[node].size(); i++)
		{
            	if(!used[A[node][i]])
			{if(B[node][i]==0)numerr++;

		if(A[node][i]!=a)used[A[node][i]] = numerr;

			q.push(A[node][i]);
			}
		}

       }

}
void input()
{
	int x, y;
	cin>>n>>a>>b;
	for(int i = 0; i < n; i++)
	{
		cin >> x >> y;
		A[x].push_back(y);
		A[y].push_back(x);
                	B[x].push_back(1);
		B[y].push_back(0);
	}
}

int main()
{
	input();
	BFS(a);
	if(used[b]>0)
              cout<<0;
              else
	{
                           for(int i=1;i<=n;i++)used[i]=0;
                           levelbfs=level-1;level=1;
	BFS1(a);



if( used[b]==0) cout<<'X';
else
cout<<used[b]-1;
}

cout<<endl;

	return 0;
}
