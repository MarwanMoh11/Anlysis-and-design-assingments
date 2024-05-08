//
// Created by Marwan on 5/6/2024.
//
#include <iostream>
#include <vector>
using namespace std;

void greedyTSP(vector<vector<int>> graph, int start) {
    int n = graph.size();
    vector<int> visited(n, 0);
    visited[start] = 1;
    int cost = 0;
    int count = 1;
    cout << "Starts at city " <<start << " " << endl;
    while (count < n) {
        int min = INT_MAX;
        int next = -1;
        for (int i = 0; i < n; i++) {
            if (graph[start][i] < min && visited[i] == 0) {
                min = graph[start][i];
                next = i;
            }
        }
        if (next == -1) {
            break;
        }
        visited[next] = 1;
        cost = cost + min;
        start = next;
        cout <<"Goes to city "<< start << " " << endl;
        count++;
    }
    cout << "Returns to city 0" << endl;
    cout << endl;
    cout << "Minimum cost using greedy: " << cost + graph[start][0] << endl;

}

void TSPBT(vector<vector<int>>& graph, vector<bool>& visited, int currPos, int n, int count, int cost, int& ans) {
    if (count == n && graph[currPos][0]) {// prunes the recursion tree if the current path cost exceeds the minimum cost
        ans = min(ans, cost + graph[currPos][0]);
        return;
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i] && graph[currPos][i]) {
            visited[i] = true;
            TSPBT(graph, visited, i, n, count + 1, cost + graph[currPos][i], ans);
            visited[i] = false;
        }
    }
}

void backtrackingTSP(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<bool> visited(n, false);
    visited[0] = true;
    int ans = INT_MAX;
    TSPBT(graph, visited, 0, n, 1, 0, ans);
    cout << "Minimum cost using backtracking : " << ans << endl;

}

int travellingSalesman(int visited_cities, int currCity, vector<vector<int>>& min_distance, int n,vector<vector<int>>& dist, int allCityVisited)
{
    if(visited_cities == allCityVisited) { //base case modified not = 0 but all the cities visited because we would know the distance to return back to the starting vertex
        return dist[currCity][0]; //dist to return back to starting vertex 0
    }
    if(min_distance[visited_cities][currCity] != -1) {
        return min_distance[visited_cities][currCity];
    }

    int ans = INT_MAX; //initialize to the maximum value of an integer at the start of each iteration
    for(int city = 0; city < n; city++) {
        if((visited_cities&(1<<city)) == 0) {
            int new_visited_cities = visited_cities | (1<<city); //new set of visited cities intialized

            //the recursive function call
            int distAns = dist[currCity][city] + travellingSalesman(new_visited_cities, city, min_distance,n,dist,allCityVisited); // modified to add the new visited variable initialized
            //The function is called with city as the new current city and visited_cities updated to include this city.

            ans = min(ans,distAns);
        }
    }
    min_distance[visited_cities][currCity] = ans;
    return min_distance[visited_cities][currCity];
    //The minimum distance for the current set of visited cities and current city is updated in the memoization table
}





int main() {
    vector<vector<int>> graph = {
            {0, 10, 15, 20},
            {10, 0, 35, 25},
            {15, 35, 0, 30},
            {20, 25, 30, 0}
    };
    greedyTSP(graph, 0);
    backtrackingTSP(graph);


    int n = graph.size();
    vector<vector<int>> min_distance((1<<n),vector<int>(n,-1));
    int allCityVisited = (1<<n) - 1;
    cout << "Minimum cost using dynamic programming: " << travellingSalesman(1, 0, min_distance, n, graph, allCityVisited) << endl;


    return 0;
}