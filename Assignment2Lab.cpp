//
// Created by Marwan on 3/28/2024.
//
#include <iostream>
#include <vector>
#include <climits>
using namespace std;



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
    int n;
    int ans = INT_MAX; //initialize to the maximum value of an integer not min that is the bug
    cout << "Welcome to the Travelling Salesman Problem!" << endl;
    cout << "Enter the number of cities:";
    cin >> n;
    int allCityVisited = (1<<n)-1; //1111
    vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

    for (int i = 0; i < n; i++) {
        dist[i][i] = 0;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                continue;
            }
            cout << "Enter the distance between city " << i << " and city " << j << ":";
            cin >> dist[i][j];
            cout << endl;
        }
    }
    vector<vector<int>> min_distance(1 << n, vector<int>(n, -1));//nx4 to accommodate all possible states of the problem
    //The set of cities visited so far is represented as a bitmask,
    //where the i-th bit is 1 if the i-th city has been visited and 0 otherwise.
    //Since there are 4 cities, there are 2^4 = 16 possible sets of cities that can be visited.
    //Hence, the first dimension of the min_distance array is 16.
    //The current city is represented as an integer between 0 and 3 (inclusive).
    //Hence, the second dimension of the min_distance array is 4.

    //the expression (1<<n) is a bit manipulation operation that uses the bitwise shift left operator <<
    for(int i = 0; i < (1<<n); i++) //(1<<4) results in 16, which in binary is 10000
    {
        for(int j = 0; j < n; j++) {
            min_distance[i][j] = -1;
        }
    }
    int shortestDistance =  travellingSalesman(1, 0, min_distance,n,dist, allCityVisited);//visited_cities=0001, currCity=0
    cout << "The shortest distance to visit all the cities is " << shortestDistance << endl;
    return 0;
}

//The use of dynamic programming and memoization in this function significantly reduces
//the time complexity from O(n!) in the naive recursive approach to O(n^2 * 2^n)