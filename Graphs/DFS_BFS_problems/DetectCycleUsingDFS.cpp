/*
Problem Statement: Given an undirected graph with V vertices and E edges, 
check whether it contains any cycle or not. 
*/

/*
Approach:
The algorithm steps are as follows:

1. In the DFS function call make sure to store the parent data along with the source node, create a visited array, and initialize to 0. The parent is stored so that while checking for re-visited nodes, we don’t check for parents. 
2. We run through all the unvisited adjacent nodes using an adjacency list and call the recursive dfs function. Also, mark the node as visited.
3. If we come across a node that is already marked as visited and is not a parent node, then keep on returning true indicating the presence of a cycle; otherwise return false after all the adjacent nodes have been checked and we did not find a cycle.
NOTE: We can call it a cycle only if the already visited node is a non-parent node because we cannot say we came to a node that was previously the parent node. 

For example, node 2 has two adjacent nodes 1 and 5. 1 is already visited but it is the parent node ( DFS(2, 1) ), So this cannot be called a cycle.
*/
//code

#include <bits/stdc++.h>
using namespace std;

class Solution {
  private: 
    bool dfs(int node, int parent, int vis[], vector<int> adj[]) {
        vis[node] = 1; 
        // visit adjacent nodes
        for(auto adjacentNode: adj[node]) {
            // unvisited adjacent node
            if(!vis[adjacentNode]) {
                if(dfs(adjacentNode, node, vis, adj) == true) 
                    return true; 
            }
            // visited node but not a parent node
            else if(adjacentNode != parent) return true; 
        }
        return false; 
    }
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
       int vis[V] = {0}; 
       // for graph with connected components 
       for(int i = 0;i<V;i++) {
           if(!vis[i]) {
               if(dfs(i, -1, vis, adj) == true) return true; 
           }
       }
       return false; 
    }
};

int main() {
    
    // V = 4, E = 2
    vector<int> adj[4] = {{}, {2}, {1, 3}, {2}};
    Solution obj;
    bool ans = obj.isCycle(4, adj);
    if (ans)
        cout << "1\n";
    else
        cout << "0\n";
    return 0;
}
/*
Output:  0

Time Complexity: O(N + 2E) + O(N), Where N = Nodes, 2E is for total degrees as we traverse all adjacent nodes. In the case of connected components of a graph, it will take another O(N) time.

Space Complexity: O(N) + O(N) ~ O(N), Space for queue data structure and visited array.
*/