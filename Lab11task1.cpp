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
        int u = pq.top().first;
        pq.pop();

    for (auto x: adj[u]){
    int v = x.first;
    int wt = x.second;

    if(dist[u] + wt < dist[v]){
        pq.push(make_pair(v, dist[u] + wt));
        dist[v] = dist[u] + wt;
     }
    }
    }

    printf("Vertex Distance from Source\n");
    for (int i = 0; i < V; ++i)
        printf("%d \t\t %d\n", i, dist[i]);
}







int main(){

    typedef pair<int, int> iPair;
    vector<iPair> adj[6];
    addEdge(adj, 0, 1, 2);
    addEdge(adj, 0, 2, 4);
    addEdge(adj, 1, 2, 1);
    addEdge(adj, 1, 3, 7);
    addEdge(adj, 2, 4, 3);
    addEdge(adj, 3, 4, 2);
    addEdge(adj, 3, 5, 0);
    addEdge(adj, 4, 5, 5);

    int src = 0;

    shortestPath(adj, 6, src);

    return 0;
}