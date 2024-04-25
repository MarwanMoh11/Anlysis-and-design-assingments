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
    adj[v].push_back(make_pair(u, wt));
//undirected graph
}

void shortestPath(vector<pair<int, int> > adj[], int V, int src) {
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;

    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(0, src));

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (auto x: adj[u]){
            int v = x.first;
            int wt = x.second;

            if(dist[u] + wt < dist[v]){
                dist[v] = dist[u] + wt;
                pq.push(make_pair(-dist[v], v));
            }
        }
    }

    printf("Vertex Distance from Source\n");
    for (int i = 0; i < V; ++i)
        printf("%d \t\t %d\n", i, dist[i]);
}







int main(){

    typedef pair<int, int> iPair;

        int V = 5; // number of vertices
        vector<pair<int,int>> adj[V]; // adjacency list

        int graph[5][5] = {
                {0, 3, 2, INT_MAX, INT_MAX},
                {3, 0, INT_MAX, 5, INT_MAX},
                {2, INT_MAX, 0, 7, 1},
                {INT_MAX, 5, 7, 0, 4},
                {INT_MAX, INT_MAX, 1, 4, 0}
        };

        for(int i = 0; i < V; i++) {
            for(int j = 0; j < V; j++) {
                if(graph[i][j] != INT_MAX) {
                    addEdge(adj, i, j, graph[i][j]);
                }
            }
        }


    int src = 1;

    shortestPath(adj, 5, src);

    return 0;
}