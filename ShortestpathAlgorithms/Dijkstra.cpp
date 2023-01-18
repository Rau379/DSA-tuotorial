#include<bits/stdc++.h>
using namespace std;
#define INF 1e9+7
// Dijkstra Algorithms
//Time complexity: O(V*V)
// vector <int> dijkstra(int V, vector<vector<int>> adj[], int src)
//     {
//               // craeting a distance array
//               int v=V;
//               vector<int>dis(v, INF);
//               vector<bool>vis(v, false);
//               dis[src]=0
             
//               // finding the vertex with the minimum distance
//               int cnt=0;
//               while (cnt<v)
//               {
//                 int min_index=-1;
//                 int mini=INT_MIN;
//                 for(int i=0; i<v; i++)
//                 {
//                     if(vis[i]==false && dis[i]<=mini)
//                     {
//                         mini= dis[i];
//                         min_index=i;
//                     }
//                 }
//                 // now traversinhg the egdes connected to this vertex and relaxation operations
//                 vis[min_index]=true;
//                 for(auto it: adj[min_index])
//                 {
//                      int temp_dis= dis[min_index]+it[1];
//                      dis[it[0]]= min(dis[it[0]], temp_dis);
//                 }
//                 cnt++;
//               }

// return dis;

//     }


// By suing priorit queue
// Time complexity:O(E*logV);
vector <int> dijkstra(int V, vector<vector<int>> adj[], int src)
{
      // Create a priority queue for storing the nodes as a pair {dist,node}
        // where dist is the distance from source to the node. 
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        // Initialising distTo list with a large number to
        // indicate the nodes are unvisited initially.
        // This list contains distance from source to the nodes.
        vector<int> distTo(V, INT_MAX);

        // Source initialised with dist=0.
        distTo[S] = 0;
        pq.push({0, S});

        // Now, pop the minimum distance node first from the min-heap
        // and traverse for all its adjacent nodes.
        while (!pq.empty())
        {
            int node = pq.top().second;
            int dis = pq.top().first;
            pq.pop();

            // Check for all adjacent nodes of the popped out
            // element whether the prev dist is larger than current or not.
            for (auto it : adj[node])
            {
                int adjnode= it[0];
                int edgeweight = it[1];
                if (dis + edgeweight < distTo[adjnode])
                {
                    distTo[adjnode] = dis + edgeweight;
    
                    // If current distance is smaller,
                    // push it into the queue.
                    pq.push({dis[adjnode], adjnode});
                }
            }
        }
        // Return the list containing shortest distances
        // from source to all the nodes.
        return distTo;
}