#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

// Helper function for containsCycle
bool isCyclicUtil(int v, vector<bool>& visited, vector<bool>& recStack, const vector<vector<pair<int,int>>>& adjList) {
    // If the current node is not visited
    if(!visited[v]) {
        // Mark the current node as visited and add it to the recursion stack
        visited[v] = true;
        recStack[v] = true;

        // Go through all the neighbors of the current node
        for(auto i : adjList[v]) {
            // If the neighbor is not visited and the recursive call for the neighbor returns true
            if (!visited[i.first] && isCyclicUtil(i.first, visited, recStack, adjList))
                return true;
                // If the neighbor is in the recursion stack
            else if (recStack[i.first])
                return true;
        }
    }
    // Remove the current node from the recursion stack
    recStack[v] = false;
    return false;
}

// Function to check if the graph contains a cycle
bool containsCycle(const vector<vector<pair<int,int>>>& adjList) {
    // Get the number of vertices
    int V = adjList.size();
    // Create a visited array
    vector<bool> visited(V, false);
    // Create a recursion stack
    vector<bool> recStack(V, false);
    // Go through all the nodes
    for(int i = 0; i < V; i++)
        // If the graph contains a cycle
        if (isCyclicUtil(i, visited, recStack, adjList))
            return true;
    return false;
}

// Helper function for DFS
void DFSUtil(int v, vector<bool>& visited, const vector<vector<pair<int,int>>>& adjList) {
    // Mark the current node as visited and print it
    visited[v] = true;
    cout << v << " ";

    // Go through all the neighbors of the current node
    for(auto i : adjList[v]) {
        // If the neighbor is not visited
        if (!visited[i.first])
            // Call DFSUtil for the neighbor
            DFSUtil(i.first, visited, adjList);
    }
}

// Function to perform a depth-first search on the graph
void DFS(int start, const vector<vector<pair<int,int>>>& adjList) {
    // Get the number of vertices
    int V = adjList.size();
    // Create a visited array
    vector<bool> visited(V, false);

    // Call DFSUtil for the starting vertex
    DFSUtil(start, visited, adjList);
}

int main() {
    // Number of vertices and edges
    int V = 5, E = 7;
    // List of edges with weights
    vector<tuple<int, int, int>> edges = {
            make_tuple(0, 1, 2),
            make_tuple(0, 4, 1),
            make_tuple(1, 2, 3),
            make_tuple(1, 3, 2),
            make_tuple(1, 4, 2),
            make_tuple(2, 3, 1),
            make_tuple(3, 4, 1)
    };

    // Create an adjacency list
    vector<vector<pair<int,int>>> adjlist(V);
    for(auto& edge: edges) {
        int u, v, w;
        // Unpack the edge
        tie(u, v, w) = edge;
        // Add the edge to the adjacency list
        adjlist[u].push_back({v, w});
        adjlist[v].push_back({u, w});
    }

    // Check if the graph contains a cycle
    if(containsCycle(adjlist)) {
        cout << "Graph contains cycle" << endl;
    } else {
        cout << "Graph does not contain cycle" << endl;
    }

    // Perform a depth-first search on the graph
    cout << "DFS traversal starting from vertex 0: ";
    DFS(0, adjlist);

    // Rest of the code
}