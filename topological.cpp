#include<bits/stdc++.h>
using namespave std;
// Definition
/*
Topological Sorting or Kahn's algorithm is an algorithm that orders a directed acylic graph in a way such that each node appears before all the nodes it points to in the returned order, i.e. if we have a --> b,
a must appear before b in the topological order.

It's main usage is to detect cycles in directed graphs, since no topological order is possible for a graph that contains a cycle. Some of it's uses are: deadlock detection in OS, Course schedule problem etc.


*/
/* Topological Osrting Using BFS*/
/*
vector<int>toposort(int V, vector<int>adj[])
{
    // Topoplogical SOrting Using BFS
    // calculating indegree of ifferent vertices
    vector<int>Indegree(V, 0);
    
    for(int i=0; i<V; i++)
    {
        // traverse the edges
        for(auto x: adj[i])
        {
            Indegree[x]++;
        }
    }
 queue<int>q;
 // pushing into the queue if the indegree is zero
 for(int u=0; u<V; u++)
 {
    if(Indegree[i]==0)
    {
        q.push(i);
    }
 }
 // now the relax operations
 vector<int>ans;
 while(!q.empty())
 {
     int node= q.front();
     q.pop();
     ans.push_back(node);
     for(auto it: adj[node])
     {
        Indegree[it]--;
        if(Indegree[i]==0)
        {
            q.push(it);
        }
     }
 }
return ans;
}

Time com- O(V+E), (V);
*/

/* Toplogical Sorting USing DFS*/

void dfs(int src, vector<int>adj[], vector<bool>&vis, stack<int>&st)
{
  vis[src]=true;
  for(auto it: adj[src])
  {
    if(!vis[it])
    {
        dfs(it, adj, vis, st);
    }
  }
  st.push(src);
}
vector<int>toposort(int V, vector<int>adj[])
{
    stack<int>st;
    vector<bool>vis(V+1, false);
    for(int i=0; i<V; i++)
    {
        if(!vis[i])
        {
            dfs(i, adj, vis, st);
        }
    }
  while(!st.empty())
  {
    cout<<st.top()<<" ";
    st.pop();
  }
}
/* Time complexity : O(V+E), SC=O(V)*/