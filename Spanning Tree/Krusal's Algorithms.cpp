#include<bits/stdc++.h>
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
class DSU{
     
    // Declaring two arrays to hold
    // information about parent and 
    // rank of each node. 
    int *parent;
    int *rank;
public:
    // Constructor
    DSU(int n){
        
        // Defining size of the arrays.
        parent=new int[n];
        rank=new int[n];
        
        // Initializing their values 
        // by is and 0s.
        for(int i=0;i<n;i++)
        {
            parent[i]=i;
            rank[i]=0;
        }
    }
    
    // Find function
    int find(int node){
        
        // If the node is the parent of 
        // itself then it is the leader 
        // of the tree. 
        if(node==parent[node]) return node;
        
        //Else, finding parent and also 
        // compressing the paths.
        return parent[node]=find(parent[node]);
    }
    
    // Union function 
     void Union(int u,int v){
        
        // Make u as a leader 
        // of its tree.
        u=find(u);
        
        // Make v as a leader 
        // of its tree.
        v=find(v);
        
        // If u and v are not equal,
        // because if they are equal then
        // it means they are already in 
        // same tree and it does not make 
        // sense to perform union operation.
        if(u!=v)
        {
            // Checking tree with 
            // smaller depth/height.
            if(rank[u]<rank[v])
            {
                int temp=u;
                u=v;
                v=temp;
            }
            // Attaching lower rank tree
            // to the higher one. 
            parent[v]=u;
            
            // If now ranks are equal
            // increasing rank of u. 
            if(rank[u]==rank[v])
                rank[u]++;
        }
    }
};
// Edge class
class Edge{
public:
    // Endpoints and weight of the edge.
    int u,v,weight;
    // Constructor
    Edge(int U,int V,int Weight){
        u=U;
        v=V;
        weight=Weight;
    }
};
class Graph{
public:
    // Number of Vertices and Edges
    int V, E;
    // List of Edge(s).
    vector<Edge> edges;
    // Constructor of Graph class
    Graph(int v,int e){
        V=v;
        E=e;
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
    void MST_Kruskal(){
        // Initializing e, i, and sum with 0.
        int e=0,i=0,sum=0;
        // Creating an object of DSU class. 
        DSU dsu(V);
        // Sorting edges using a custom comparator
        sort(edges.begin(), edges.end(), comparator);
        
        // Iterating till we include V-1 edges in MST
        while(e<V-1)
        {
            Edge edge=edges[i++];
            
            int u=dsu.find(edge.u);
            int v=dsu.find(edge.v);
            // Checking if adding edge with endpoints
            // u and v form a cycle.
            // If not
            if(u!=v)
            {
                cout<<"Adding edge "<<edge.u<<" <---> "<<edge.v<<" to MST\n";
                // Adding the weight of current edge to total
                // weight of the MST.
                sum+=edge.weight;
                // Including the edge.
                dsu.Union(u,v);
                // Increasing the edge count.
                e++;
            }
        }
        // Printing the total sum of the MST.
        cout<<"MST has a weight of "<<sum;
    }
    // Function to add edges.
    void addEdge(int u,int v,int weight){
        edges.push_back(Edge(u,v,weight));
    }
};
int main(){
    // Creating an object of Graph type.
    Graph g(6,9);
    
    // Adding 9 edges to make the same
    // graph as given in examples.
    g.addEdge(0,1,7);
    g.addEdge(0,2,8);
    g.addEdge(1,2,3);
    g.addEdge(1,4,6);
    g.addEdge(2,3,3);
    g.addEdge(2,4,4);
    g.addEdge(3,4,2);
    g.addEdge(3,5,2);
    g.addEdge(4,5,2);
    
    // Calling the MST_Kruskal Function.
    g.MST_Kruskal();
    return 0;
}
//In Kruskal’s algorithm, most time consuming operation is sorting because the total complexity of the Disjoint-Set operations will be , 
//which is the overall Time Complexity of the algorithm.


