#include <bits/stdc++.h>
using namespace std;
/*
Kruskal's algorithm is a greedy algorithm in graph theory that is used to find the Minimum spanning tree (A subgraph of a graph G(V,E)G(V,E)
which is a tree and includes all the vertices of the given graph such that the sum of the weight of the edges is minimum) of a given connected,
weighted, undirected graph. In case, the graph is not connected, on applying Kruskal's algorithm we can find the MST of each connected component.
 */
// Sample Code
// Using DSU to quickly
// tell whether adding edge
// will form a cycle.
class DSU
{

    // Declaring two arrays to hold
    // information about parent and
    // rank of each node.
    int *parent;
    int *rank;

public:
    // Constructor
    DSU(int n)
    {

        // Defining size of the arrays.
        parent = new int[n];
        rank = new int[n];

        // Initializing their values
        // by is and 0s.
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
            rank[i] = 0;
        }
    }

    // Find function
    int find(int node)
    {

        // If the node is the parent of
        // itself then it is the leader
        // of the tree.
        if (node == parent[node])
            return node;

        // Else, finding parent and also
        //  compressing the paths.
        return parent[node] = find(parent[node]);
    }

    // Union function
    void Union(int u, int v)
    {

        // Make u as a leader
        // of its tree.
        u = find(u);

        // Make v as a leader
        // of its tree.
        v = find(v);

        // If u and v are not equal,
        // because if they are equal then
        // it means they are already in
        // same tree and it does not make
        // sense to perform union operation.
        if (u != v)
        {
            // Checking tree with
            // smaller depth/height.
            if (rank[u] < rank[v])
            {
                int temp = u;
                u = v;
                v = temp;
            }
            // Attaching lower rank tree
            // to the higher one.
            parent[v] = u;

            // If now ranks are equal
            // increasing rank of u.
            if (rank[u] == rank[v])
                rank[u]++;
        }
    }
};
// Edge class
class Edge
{
public:
    // Endpoints and weight of the edge.
    int u, v, weight;
    // Constructor
    Edge(int U, int V, int Weight)
    {
        u = U;
        v = V;
        weight = Weight;
    }
};
class Graph
{
public:
    // Number of Vertices and Edges
    int V, E;
    // List of Edge(s).
    vector<Edge> edges;
    // Constructor of Graph class
    Graph(int v, int e)
    {
        V = v;
        E = e;
        // // Initializing list of edges.
        // edges=new ArrayList<>();
    }
    // comparator to compare two edges
    // based on their edges.
    static bool comparator(Edge e1, Edge e2)
    {
        return e1.weight < e2.weight;
    }
    // Function responsible to print MST.
    void MST_Kruskal()
    {
        // Initializing e, i, and sum with 0.
        int e = 0, i = 0, sum = 0;
        // Creating an object of DSU class.
        DSU dsu(V);
        // Sorting edges using a custom comparator
        sort(edges.begin(), edges.end(), comparator);

        // Iterating till we include V-1 edges in MST
        while (e < V - 1)
        {
            Edge edge = edges[i++];

            int u = dsu.find(edge.u);
            int v = dsu.find(edge.v);
            // Checking if adding edge with endpoints
            // u and v form a cycle.
            // If not
            if (u != v)
            {
                cout << "Adding edge " << edge.u << " <---> " << edge.v << " to MST\n";
                // Adding the weight of current edge to total
                // weight of the MST.
                sum += edge.weight;
                // Including the edge.
                dsu.Union(u, v);
                // Increasing the edge count.
                e++;
            }
        }
        // Printing the total sum of the MST.
        cout << "MST has a weight of " << sum;
    }
    // Function to add edges.
    void addEdge(int u, int v, int weight)
    {
        edges.push_back(Edge(u, v, weight));
    }
};
int main()
{
    // Creating an object of Graph type.
    Graph g(6, 9);

    // Adding 9 edges to make the same
    // graph as given in examples.
    g.addEdge(0, 1, 7);
    g.addEdge(0, 2, 8);
    g.addEdge(1, 2, 3);
    g.addEdge(1, 4, 6);
    g.addEdge(2, 3, 3);
    g.addEdge(2, 4, 4);
    g.addEdge(3, 4, 2);
    g.addEdge(3, 5, 2);
    g.addEdge(4, 5, 2);

    // Calling the MST_Kruskal Function.
    g.MST_Kruskal();
    return 0;
}
// In Kruskal’s algorithm, most time consuming operation is sorting because the total complexity of the Disjoint-Set operations will be ,
// which is the overall Time Complexity of the algorithm.

// take u forward code

#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
    vector<int> rank, parent, size;

public:
    DisjointSet(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v)
            return;
        if (rank[ulp_u] < rank[ulp_v])
        {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u])
        {
            parent[ulp_v] = ulp_u;
        }
        else
        {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v)
            return;
        if (size[ulp_u] < size[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
class Solution
{
public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // 1 - 2 wt = 5
        /// 1 - > (2, 5)
        // 2 -> (1, 5)

        // 5, 1, 2
        // 5, 2, 1
        vector<pair<int, pair<int, int>>> edges;
        for (int i = 0; i < V; i++)
        {
            for (auto it : adj[i])
            {
                int adjNode = it[0];
                int wt = it[1];
                int node = i;

                edges.push_back({wt, {node, adjNode}});
            }
        }
        DisjointSet ds(V);
        sort(edges.begin(), edges.end());
        int mstWt = 0;
        for (auto it : edges)
        {
            int wt = it.first;
            int u = it.second.first;
            int v = it.second.second;

            if (ds.findUPar(u) != ds.findUPar(v))
            {
                mstWt += wt;
                ds.unionBySize(u, v);
            }
        }

        return mstWt;
    }
};

int main()
{

    int V = 5;
    vector<vector<int>> edges = {{0, 1, 2}, {0, 2, 1}, {1, 2, 1}, {2, 3, 2}, {3, 4, 1}, {4, 2, 2}};
    vector<vector<int>> adj[V];
    for (auto it : edges)
    {
        vector<int> tmp(2);
        tmp[0] = it[1];
        tmp[1] = it[2];
        adj[it[0]].push_back(tmp);

        tmp[0] = it[0];
        tmp[1] = it[2];
        adj[it[1]].push_back(tmp);
    }

    Solution obj;
    int mstWt = obj.spanningTree(V, adj);
    cout << "The sum of all the edge weights: " << mstWt << endl;
    return 0;
}
