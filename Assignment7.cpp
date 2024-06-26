//
// Created by Marwan on 4/14/2024.
//

#include <iostream>
#include <vector>
using namespace std;

void digitmaxhelper(string n, int swaps, string& max_num, int index = 0){
    if(swaps == 0){
        max_num = max(max_num, n);
        return;
    }
    for (int i = index; i < n.length(); i++){
        swap(n[index], n[i]);
        digitmaxhelper(n, swaps - 1, max_num, index + 1);
        swap(n[index], n[i]); // backtrack
    }
}

int digitmax(int k, int swaps) {
    string str = to_string(k);
    string max_num = str;
    digitmaxhelper(str, swaps, max_num);
    return stoi(max_num);
}



int greedychroma(vector<vector<int>>& adj, int V){
    vector<int> results(V,-1);
    results[0] = V - 1; // start coloring from the highest degree vertex
    int max_color = V - 1;
    for(int i = 1; i < V; i++){
        vector<bool> available(V, true);
        for(int j = 0; j < adj[i].size(); j++){
            if(results[adj[i][j]] != -1){
                available[results[adj[i][j]]] = false;
            }
        }
        for(int j = 0; j < V; j++){
            if(available[j]){
                results[i] = j;
                max_color = max(max_color, j);
                break;
            }
        }
    }

    return max_color; // because the colors are 0 indexed we need to add 1 to get the actual number of colors used
}

bool graphcoloringhelper(vector<vector<int>>& adj, int V, int m, vector<int>& results, int vertex){
    if(vertex == V){
        return true;
    }

    for(int i = 0; i < m; i++){
        bool isSafe = true;
        for(int j = 0; j < V; j++){
            if(adj[vertex][j] && i == results[j]){
                isSafe = false;
                break;
            }
        }
        if(isSafe){
            results[vertex] = i;
            if(graphcoloringhelper(adj, V, m, results, vertex + 1)){
                return true;
            }
            results[vertex] = -1;
        }
    }
    return false;
}

int backtrackingchroma(vector<vector<int>>& adj, int V){
    vector<int> results(V, -1);
    for(int m = 1; m <= V; m++){
        if(graphcoloringhelper(adj, V, m, results, 0)){
            return m; // if the graph can be colored with m colors
        }
    }
    return -1;
}



int main(){
    int k, swaps;
    cout << "Enter a number:";
    cin >> k;
    cout << "Enter the number of swaps:";
    cin >> swaps;
    cout << "The maximum number after " << swaps << " swaps is: " << digitmax(k, swaps) << endl;


    vector<vector<int>> adj = {
            {0, 1, 1, 1},
            {1, 0, 1, 0},
            {1, 1, 0, 1},
            {1, 0, 1, 0}
    };
    cout << greedychroma(adj, 4) << endl;
    cout << backtrackingchroma(adj, 4) << endl;
    return 0;
}
