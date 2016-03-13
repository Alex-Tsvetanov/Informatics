#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > graph(10,vector<int >());
map<int,int> m;

void bfs(int k)
{
    queue<int> q;
    q.push(k);
    while(q.size() != 0){
        int val = q.front();
        cout<<val<<" ";
        q.pop();
        for(int i = 0; i < (int)graph[val].size() ; i++){
            q.push(graph[val][i]);
        }
    }
}
int dfs(int k){
    if(m[k] != 0){
        return 1;
    }
    else{
        m[k] = 1;
        for(int i =0; i < graph[k].size() ;i++ ){
            if(dfs(graph[k][i]))
                return 1;
        }
    }
    return 0;
}
#include <string>
#include <iostream>
using namespace std;
#include <stdio.h>
#include <exception>
std::vector <string> Split (std::string line, std::string sep = " \t\n")
{
	    std::string str = line;
		std::string curr;
	    vector < string > ans;
	    for (size_t i = 0 ; i < str.size () ; i ++)
		if (sep.find (str [i]) != string::npos)
		{
		    if (curr != "")
		    {
				    ans.push_back (string (curr)); curr = "";
			    }
		}
		else
		    curr += str [i];
	    if (curr.size () > 0)
		ans.push_back (curr);
	    return ans;
}

std::logic_error NotImplementedException ()
{
    return std::logic_error ("Function not yet implemented.");
}

char ConsoleReadKey ()
{
    try
    {
		throw NotImplementedException ();
		return cin.get ();
    }
    catch (std::exception& e)
    {
		throw e;
    }
}
char ConsoleRead ()
{
    try
    {
	char out;
	cin >> out;
	return out;
    }
    catch (std::exception& e)
    {
	throw e;
    }
}
string ConsoleReadLine ()
{
    try
    {
	string out;
	getline (cin, out);
	return out;
    }
    catch (std::exception& e)
    {
	throw e;
    }
}

int main() {
	int n;
	cin >> n;
	for (int i = 0 ; i < n ; i ++)
	{
		string line = ConsoleReadLine ();
		if (line == "")
		    line = ConsoleReadLine ();
		vector <string> splitted = vector <string> (Split (line, " ->"));
		int from = atoi (splitted [0].c_str ());
		for (int i = 1 ; i < (int)splitted.size () ; i ++)
		{
			int to = atoi (splitted [i].c_str ());
			graph [from].addEdge (to);
		}
	}


    cout<<"\n";
    int l = dfs(0);
    if(l == 1)
    {
        cout<<"loop";
    }
    else cout<<"not";


    return 0;
}
