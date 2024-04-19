//
// Created by Marwan on 4/19/2024.
//

#include <iostream>
#include <list>
#include <unordered_set>
using namespace std;

bool R_solve_maze(list<int>* maze, int start, int destination, unordered_set<int>& visited, list<int>& path)
{
    //base case
    if(start == destination)
    {
        path.push_back(start);
        return true;
    }

    //write code here
    for(int x : maze[start]){
        if(visited.find(x) == visited.end()){
            visited.insert(x);
            if(R_solve_maze(maze, x, destination, visited, path)){
                path.push_front(start);//add the current node to the path
                return true;
            }
        }
    }
    return false;

}
list<int> R_solve_maze(list<int>* maze, int start, int destination)
{
    unordered_set<int> visited;
    list<int> path;

    R_solve_maze(maze, start, destination, visited, path);
    return path;
}
int main()
{


    list<int> maze[9];
    maze[0].push_back(1);
    maze[0].push_back(3);
    maze[1].push_back(0);
    maze[1].push_back(2);
    maze[2].push_back(1);
    maze[3].push_back(0);
    maze[3].push_back(4);
    maze[3].push_back(6);
    maze[4].push_back(3);
    maze[4].push_back(5);
    maze[4].push_back(7);
    maze[5].push_back(4);
    maze[6].push_back(3);
    maze[7].push_back(4);
    maze[7].push_back(8);
    maze[8].push_back(7);



    list<int> maze_1[5];
    maze_1[0].push_back(1);
    maze_1[1].push_back(0);
    maze_1[1].push_back(2);
    maze_1[2].push_back(1);
    maze_1[2].push_back(3);
    maze_1[3].push_back(2);
    maze_1[3].push_back(4);
    maze_1[4].push_back(3);


    list<int> maze_2[5];
    maze_2[0].push_back(1);
    maze_2[1].push_back(0);
    maze_2[1].push_back(2);
    maze_2[2].push_back(1);
    maze_2[2].push_back(3);
    maze_2[3].push_back(2);

    list<int> solution = R_solve_maze(maze, 0, 8);
    list<int> solution_1 = R_solve_maze(maze_1, 0, 4);
    list<int> solution_2 = R_solve_maze(maze_2, 0, 4);

    //print out the solution(s)
    cout<<"Path found by recursive solution: ";
    list<int>::iterator iter;
    for(iter = solution.begin(); iter !=solution.end(); iter++)
    {
        cout<< *iter << ", ";
    }
    cout<<endl;
    cout<<"Path found by recursive solution: ";
    list<int>::iterator iter1;
    for(iter = solution_1.begin(); iter !=solution_1.end(); iter++)
    {
        cout<< *iter << ", ";
    }
    cout<<endl;
    cout<<"Path found by recursive solution: ";
    list<int>::iterator iter2;
    for(iter = solution_2.begin(); iter !=solution_2.end(); iter++)
    {
        cout<< *iter << ", ";
    }
    cout<<endl;
    return 0;
}