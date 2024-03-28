//
// Created by Marwan on 3/28/2024.
//
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int dist[4][4] = {{0, 20, 42, 25},{20, 0 , 30, 34}, {42, 30, 0, 10}, {25, 34, 10, 0}};
int n = 4;
int allCityVisited = (1<<n)-1; //1111
// (1<<4) results in 16, which in binary is 10000
// (1<<n)-1 is used to represent the state where all cities have been visited:
// it results in a number where the n least significant bits are all set to 1

int travellingSalesman(int visited_cities, int currCity, vector<vector<int>>& min_distance)
{
    if(visited_cities == 0) {
        return dist[currCity][0]; //dist to return back to starting vertex 0
    }
    if(min_distance[visited_cities][currCity] != -1) {
        return min_distance[visited_cities][currCity];
    }
    int ans = INT_MIN;
    for(int city = 0; city < n; city++) {
        if((visited_cities&(1<<city)) == 0) {
            visited_cities = visited_cities | (1<<city);

            //the recursive function call
            int distAns = dist[currCity][city] + travellingSalesman(visited_cities, city, min_distance);
            //The function is called with city as the new current city and visited_cities updated to include this city.

            ans = min(ans,distAns);
            visited_cities = visited_cities & (~(1<<city)); //bitwise AND operator with the bitwise NOT
        }
    }
    min_distance[visited_cities][currCity] = ans;
    return min_distance[visited_cities][currCity];
    //The minimum distance for the current set of visited cities and current city is updated in the memoization table
}

int main() {
    int ans = INT_MAX;
    vector<vector<int>> min_distance(16, vector<int>(4, -1)); //16x4 to accommodate all possible states of the problem
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
    int shortestDistance =  travellingSalesman(1, 0, min_distance);//visited_cities=0001, currCity=0
    cout << "The shortest distance to visit all the cities is " << shortestDistance << endl;
    return 0;
}

//The use of dynamic programming and memoization in this function significantly reduces
//the time complexity from O(n!) in the naive recursive approach to O(n^2 * 2^n)