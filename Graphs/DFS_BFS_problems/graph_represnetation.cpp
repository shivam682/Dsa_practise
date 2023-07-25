/*
Graph Representations
After understanding the input format, let us try to understand how the graph can be stored. The two most commonly used representations for graphs are

1.Adjacency Matrix
2.Adjacency Lists


Adjacency Matrix
An adjacency matrix of a graph is a two-dimensional array of size n x n, where n is the number of nodes in the graph, with the property that a[ i ][ j ] = 1 if the edge (vᵢ, vⱼ) is in the set of edges, 
and a[ i ][ j ] = 0 if there is no such edge.

*/
# include<bits/stdc++.h>
using namespace std;

int main()
{
   /* 
   int n, m;
    cin >> n >> m;
    // adjacency matrix for undirected graph
    // time complexity: O(n)
    int adj[n+1][n+1];
    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1 ; // this statement will be removed in case of directed graph
    }
    return 0;
    */

    /*
    Adjacency Lists
        In the previous storing method, we saw it was taking n² space to store the graph, this is where the adjacency list comes into the picture, it takes a very less amount of space.

        This is a node-based representation. In this representation, we associate with each node a list of nodes adjacent to it. Normally an array is used to store the nodes. 
        The array provides random access to the adjacency list for any particular node.
        To create an adjacency list, we will create an array of size n+1 where n is the number of nodes. This array will contain a list, so in C++ list is nothing but the vector of integers
    */
   /*
   int n, m;
    cin >> n >> m;
    // adjacency list for undirected graph
    // time complexity: O(2E)
    vector<int> adj[n+1];
    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    return 0;
    */
   /*
   For directed graphs, if there is an edge between u and v it means the edge only goes from u to v, i.e., 
   v is the neighbor of u, but vice versa is not true. The space needed to represent a directed graph using
    its adjacency list is E locations, where E denotes the number of edges, as here each edge data appears only once.
   */
  /*
    int n, m;
    cin >> n >> m;
    // adjacency list for directed graph
    // time complexity: O(E)
    vector<int> adj[n+1];
    for(int i = 0; i < m; i++)
    {
        int u, v;
        // u —> v
        cin >> u >> v;
        adj[u].push_back(v);
    }
    return 0;
  */



}
