/*
probelm statement:
Given a DAG, find the shortest path from the 
source to all other nodes in this DAG. In this 
problem statement, we have assumed the source
vertex to be ‘0’. You will be given the weighted 
edges of the graph.
*/

/*
Approach:
We will calculate the shortest path in a directed acyclic graph by using topological sort. Topological sort can be implemented in two ways- BFS and DFS. Here, we will be implementing using the DFS technique. Depth First Search, DFS is a traversal technique where we visit a node and then continue visiting its adjacent nodes until we reach the end point, i.e., it keeps on moving in the depth of a particular node and then backtracks when no further adjacent nodes are available. 

Initial configuration:
1. Adjacency List: Create an adjacency list of the formed vector of pairs of size ‘N’, where each index denotes a node ‘u’ and contains a vector that consists of pairs denoting the adjacent nodes ‘v’ and the distance to that adjacent node from initial node ‘u’.
2. Visited Array: Create a visited array and mark all the indices as unvisited (0) initially.
3. Stack: Define a stack data structure to store the topological sort.
4. Distance Array: Initialise this array by Max integer value and then update the value for each node successively while calculating the shortest distance between the source and the current node.
The shortest path in a directed acyclic graph can be calculated by the following steps:

1. Perform topological sort on the graph using BFS/DFS and store it in a stack. In order to get a hang of how the Topological Sort works, you can refer to this article for the same. 
2. Now, iterate on the topo sort. We can keep the generated topo sort in the stack only, and do an iteration on it, it reduces the extra space which would have been required to store it. Make sure for the source node, we will assign dist[src] = 0. 
3. For every node that comes out of the stack which contains our topo sort, we can traverse for all its adjacent nodes, and relax them. 
4. In order to relax them, we simply do a simple comparison of dist[node] + wt and dist[adjNode]. Here dist[node] means the distance taken to reach the current node, and it is the edge weight between the node and the adjNode. 
5. If (dist[node] + wt < dist[adjNode]), then we will go ahead and update the distance of the dist[adjNode] to the new found better path. 
Once all the nodes have been iterated, the dist[] array will store the shortest paths and we can then return it.
*/

//code
#include<bits/stdc++.h>

using namespace std;

class Solution {
  private:
    void topoSort(int node, vector < pair < int, int >> adj[],
      int vis[], stack < int > & st) {
      //This is the function to implement Topological sort. 
      vis[node] = 1;
      for (auto it: adj[node]) {
        int v = it.first;
        if (!vis[v]) {
          topoSort(v, adj, vis, st);
        }
      }
      st.push(node);
    }
  public:
    vector < int > shortestPath(int N, int M, vector < vector < int >> & edges) {

      //We create a graph first in the form of an adjacency list.
      vector < pair < int, int >> adj[N];
      for (int i = 0; i < M; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int wt = edges[i][2];
        adj[u].push_back({v, wt}); 
      }
      // A visited array is created with initially 
      // all the nodes marked as unvisited (0).
      int vis[N] = {
        0
      };
      //Now, we perform topo sort using DFS technique 
      //and store the result in the stack st.
      stack < int > st;
      for (int i = 0; i < N; i++) {
        if (!vis[i]) {
          topoSort(i, adj, vis, st);
        }
      }
      //Further, we declare a vector ‘dist’ in which we update the value of the nodes’
      //distance from the source vertex after relaxation of a particular node.

      vector < int > dist(N);
      for (int i = 0; i < N; i++) {
        dist[i] = 1e9;
      }

      dist[0] = 0;
      while (!st.empty()) {
        int node = st.top();
        st.pop();

        for (auto it: adj[node]) {
          int v = it.first;
          int wt = it.second;

          if (dist[node] + wt < dist[v]) {
            dist[v] = wt + dist[node];
          }
        }
      }

      for (int i = 0; i < N; i++) {
        if (dist[i] == 1e9) dist[i] = -1;
      }
      return dist;
    }
};

int main() {

  int N = 6, M = 7;
  
  vector<vector<int>> edges= {{0,1,2},{0,4,1},{4,5,4},{4,2,2},{1,2,3},{2,3,6},{5,3,1}};
  Solution obj;
  vector < int > ans = obj.shortestPath(N, M, edges);

  for (int i = 0; i < ans.size(); i++) {

    cout << ans[i] << " ";
  }

  return 0;

}
/*
Output: 

0 2 3 6 1 5 

Time Complexity: O(N+M) {for the topological sort} + O(N+M) {for relaxation of vertices, each node and its adjacent nodes get traversed} ~ O(N+M).

Where N= number of vertices and M= number of edges.

Space Complexity:  O( N) {for the stack storing the topological sort} + O(N) {for storing the shortest distance for each node} + O(N) {for the visited array} + O( N+2M) {for the adjacency list} ~ O(N+M) .

Where N= number of vertices and M= number of edges.
*/