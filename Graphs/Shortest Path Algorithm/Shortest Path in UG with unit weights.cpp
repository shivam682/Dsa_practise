/*
Problem Statement:
Given an Undirected Graph having unit weight, 
find the shortest path from the source to all 
other nodes in this graph. In this problem statement
, we have assumed the source vertex to be ‘0’. 
If a vertex is unreachable from the source node, 
then return -1 for that vertex.
*/

/*
Approach:

According to intuition, we will calculate the shortest path in an undirected graph having unit weights by using the Breadth First Search. BFS is a traversal technique where we visit the nodes level-wise, i.e., it visits the same level nodes simultaneously, and then moves to the next level.

Initial configuration:

Adjacency List: Create an adjacency list of the formed vector of pairs of size ‘N’, where each index denotes a node ‘u’ and contains a vector that consists of pairs denoting the adjacent nodes ‘v’ and the distance to that adjacent node from initial node ‘u’.
Queue: Define a queue data structure to store the BFS traversal.
Distance Array: Initialise this array by Max Integer value and then update the value for each node successively while calculating the shortest distance between the source and the current node.
Resultant Array: Initialised with -1, this array stores the updated shortest distances from the source node after completion of the algorithm. The index which remains as -1 is said to be unreachable from the source node. This is required to return the answer according to the question. 
The shortest path in an undirected graph can be calculated by the following steps:

1. Firstly, we convert the graph into an adjacency list which displays the adjacent nodes for each index represented by a node.
2. Now, we create a dist array of size N initialized with a very large number which can never be the answer to indicate that initially, all the nodes are untraversed.
3. Then, perform the standard BFS traversal. 
4. In every iteration, pick up the front() node, and then traverse for its adjacent nodes.  For every adjacent node, we will relax the distance to the adjacent node if (dist[node] + 1 < dist[adjNode]). Here dist[node] means the distance taken to reach the current node, and ‘1’ is the edge weight between the node and the adjNode. We will relax the edges if this distance is shorter than the previously taken distance. Every time a distance is updated for the adjacent node, we push that into the Queue with the increased distance. 
*/

// code
#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
    //Create an adjacency list of size N for storing the undirected graph.
        vector<int> adj[N]; 
        for(auto it : edges) {
            adj[it[0]].push_back(it[1]); 
            adj[it[1]].push_back(it[0]); 
        }

        //A dist array of size N initialised with a large number to 
        //indicate that initially all the nodes are untraversed.    
    
        int dist[N];
        for(int i = 0;i<N;i++) dist[i] = 1e9;
        // BFS Implementation.
        dist[src] = 0; 
        queue<int> q;
        q.push(src); 
        while(!q.empty()) {
            int node = q.front(); 
            q.pop(); 
            for(auto it : adj[node]) {
                if(dist[node] + 1 < dist[it]) {
                    dist[it] = 1 + dist[node]; 
                    q.push(it); 
                }
            }
        }
        // Updated shortest distances are stored in the resultant array ‘ans’.
        // Unreachable nodes are marked as -1. 
        vector<int> ans(N, -1);
        for(int i = 0;i<N;i++) {
            if(dist[i] != 1e9) {
                ans[i] = dist[i]; 
            }
        }
        return ans; 
    }
};

int main(){

int N=9, M=10;
vector<vector<int>> edges= {{0,1},{0,3},{3,4},{4,5},{5,6},{1,2},{2,6},{6,7},{7,8},{6,8}};

Solution obj;
vector<int> ans = obj.shortestPath(edges,N,M,0);

for(int i=0;i<ans.size();i++){
    
    cout<<ans[i]<<" ";
}

return 0;
}
/*
Output: 

0 1 2 1 2 3 3 4 4 

Time Complexity: O(M) { for creating the adjacency list from given list ‘edges’} + O(N + 2M) { for the BFS Algorithm} + O(N) { for adding the final values of the shortest path in the resultant array} ~ O(N+2M). 

Where N= number of vertices and M= number of edges.

Space Complexity:  O( N) {for the stack storing the BFS} + O(N) {for the resultant array} + O(N) {for the dist array storing updated shortest paths} + O( N+2M) {for the adjacency list} ~ O(N+M) .

Where N= number of vertices and M= number of edges.
*/