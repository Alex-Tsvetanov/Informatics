#include<iostream>
#include<map>
#include<vector>

using namespace std;

map<long long,  vector<long long> > graph;
vector <long long> ans;

int main(){

    int p, m;
    cin >> p >> m;
    for(int i = 0; i < m; i ++){
        long long a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    int k;
    cin >> k;

    for(map<long long, vector<long long> >::iterator it = graph.begin(); it != graph.end(); it ++){
        if(it->second.size() >= k){
            ans.push_back(it->first);
        }
    }
    cout << ans.size() << "\n";

    for(int i = 0 ; i < ans.size() - 1; i ++){
        cout << ans[i] << " ";
    }
    cout << ans[ans.size()-1] << "\n";

	return 0;
}
