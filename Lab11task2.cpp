//
// Created by Marwan on 4/25/2024.
//
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void addEdge(vector<pair<int,int>> adj[],
             int u, int v, int wt)
{
    adj[u].push_back(make_pair(v, wt));

//undirected graph
}

void shortestPathbellman(vector<pair<int, int> > adj[], int V, int src) {
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;

    for(int k = 0; k < V-1; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < adj[i].size(); j++) {
                if (dist[i] != INT_MAX && dist[i] + adj[i][j].second < dist[adj[i][j].first]) {
                    dist[adj[i][j].first] = dist[i] + adj[i][j].second;
                }

            }
        }
    }

    // Check for negative weight cycle
    for (int u = 0; u < V; u++) {
        for (auto edge : adj[u]) {
            int v = edge.first;
            int weight = edge.second;
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                cout << "Graph contains negative weight cycle" << endl;
                return;
            }
        }
    }


    printf("Vertex Distance from Source\n");
    for (int i = 0; i < V; ++i)
        printf("%d \t\t %d\n", i, dist[i]);
}







int main(){

    typedef pair<int, int> iPair;
    vector<iPair> adj1[6];
    addEdge(adj1, 0, 1, 2);
    addEdge(adj1, 1, 2, 1);
    addEdge(adj1, 1, 3, 7);
    addEdge(adj1, 2, 4, 3);
    addEdge(adj1, 3, 4, 2);
    addEdge(adj1, 3, 5, 1);
    addEdge(adj1, 4, 5, 5);

    int src = 0;

    shortestPathbellman(adj1, 6, src);
    cout << endl;

    vector<iPair> adj2[6];
    addEdge(adj2, 0, 1, 2);
    addEdge(adj2, 0, 2, 4);
    addEdge(adj2, 1, 2, -2); // Negative edge
    addEdge(adj2, 1, 3, 7);
    addEdge(adj2, 2, 4, 3);
    addEdge(adj2, 3, 4, 2);
    addEdge(adj2, 3, 5, 1);
    addEdge(adj2, 4, 5, 5);
    addEdge(adj2, 5, 1, -8); // Edge creating a negative cycle



    shortestPathbellman(adj2, 6, src);




    return 0;
}