#include <iostream>
#include <list>
#include <stack>
using namespace std;
/*
//Kosaraju's Algorithms
1. Store all the nodes in the stack
2.Transpose the graph
3.Do DFs according to the stack nodes on the transpose graph


Strongly connected components (SCC's) are directed graph or a part of a directed graph in which each and every node is reachable from one another
 or in other words, there is a path between each and every vertex. There are many ways to find strongly connected components in any graph with the
 most efficient algorithm being Tarjan's Algorithm which uses DFS to find strongly connected components.
*/
class Graph
{
	int V;
	list<int> *adj;

	void fillOrder(int v, bool visited[], stack<int> &s);

	void DFSUtil(int v, bool visited[]);

public:
	Graph(int V);
	void addEdge(int v, int w);

	void printSCCs();

	Graph getTranspose();
};

Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
}

void Graph::DFSUtil(int v, bool visited[])
{
	visited[v] = true;
	cout << v << " ";

	list<int>::iterator i;
	for (i = adj[v].begin(); i != adj[v].end(); ++i)
		if (!visited[*i])
			DFSUtil(*i, visited);
}

Graph Graph::getTranspose()
{
	Graph g(V);
	for (int v = 0; v < V; v++)
	{
		list<int>::iterator i;
		for (i = adj[v].begin(); i != adj[v].end(); ++i)
		{
			g.adj[*i].push_back(v);
		}
	}
	return g;
}

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w);
}

void Graph::fillOrder(int v, bool visited[], stack<int> &s)
{
	visited[v] = true;

	list<int>::iterator i;
	for (i = adj[v].begin(); i != adj[v].end(); ++i)
		if (!visited[*i])
			fillOrder(*i, visited, s);

	s.push(v);
}

void Graph::printSCCs()
{
	stack<int> s;

	bool *visited = new bool[V];
	for (int i = 0; i < V; i++)
		visited[i] = false;

	for (int i = 0; i < V; i++)
		if (visited[i] == false)
			fillOrder(i, visited, s);

	Graph gr = getTranspose();

	for (int i = 0; i < V; i++)
		visited[i] = false;

	while (s.empty() == false)
	{
		int v = s.top();
		s.pop();

		if (visited[v] == false)
		{
			gr.DFSUtil(v, visited);
			cout << endl;
		}
	}
}

int main()
{
	Graph g(5);
	g.addEdge(1, 0);
	g.addEdge(0, 2);
	g.addEdge(2, 1);
	g.addEdge(0, 3);
	g.addEdge(3, 4);

	cout << "Following are strongly connected components in given graph \n";
	g.printSCCs();

	return 0;
}

// Approach by Shardha Khapra
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
	// Function to find number of strongly connected components in the graph.

	void topo(int vertex, vector<int> adj[], stack<int> &stk, vector<int> &vis)
	{
		vis[vertex] = 1;

		for (auto child : adj[vertex])
		{
			if (!vis[child])
				topo(child, adj, stk, vis);
		}
		// At this point vertex if fully explored
		stk.push(vertex);
	}

	void dfs(int vertex, vector<int> trans[], vector<int> &vis)
	{
		vis[vertex] = 1;

		for (auto child : trans[vertex])
		{
			if (!vis[child])
				dfs(child, trans, vis);
		}
	}

	int kosaraju(int V, vector<int> adj[])
	{
		// code here
		vector<int> vis(V, 0);
		stack<int> stk;

		for (int i = 0; i < V; i++)
		{
			if (!vis[i])
				topo(i, adj, stk, vis);
		}

		// transpose
		vector<int> trans[V];
		for (int i = 0; i < V; i++)
		{
			vis[i] = 0;
			for (auto child : adj[i])
			{
				trans[child].push_back(i);
			}
		}

		int count = 0;
		while (!stk.empty())
		{
			int i = stk.top();
			stk.pop();
			if (!vis[i])
			{
				count++;
				dfs(i, trans, vis);
			}
		}

		return count;
	}
};

//{ Driver Code Starts.

int main()
{

	int t;
	cin >> t;
	while (t--)
	{
		int V, E;
		cin >> V >> E;

		vector<int> adj[V];

		for (int i = 0; i < E; i++)
		{
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
		}

		Solution obj;
		cout << obj.kosaraju(V, adj) << "\n";
	}

	return 0;
}

// } Driver Code Ends