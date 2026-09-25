# Analysis and Design of Algorithms: coursework

My labs and assignments from the Analysis and Design of Algorithms course at AUC (spring 2024), in C++.

| Topic | Files |
|---|---|
| Optimal merge pattern for sorted files | `Analysis_Assign1.1.cpp` |
| Huffman coding (encode and decode) | `Analysis_Assign1.2.cpp`, `Lab3Task2.cpp` |
| Greedy job scheduling with deadlines | `Lab3Task1.cpp` |
| Travelling salesman: greedy vs. backtracking | `Assignment2.2.cpp`, `Assignment2Lab.cpp` |
| Graph colouring: greedy vs. backtracking | `Assignment7.cpp` |
| Closest pair of points (divide and conquer) | `Lab6.cpp` |
| Matrix-chain multiplication (dynamic programming) | `lab7.cpp` |
| Cycle detection with DFS | `Lab8Graph.cpp` |
| Backtracking: knight's tour, maze paths, longest path over hurdles, code cracking | `Labtask10A.cpp`, `Labtask10B.cpp`, `Labtask10C.cpp`, `Marwan_Abudaif_BT_Maze.cpp`, `Marwan_Abudaif_BT_Hurdles.cpp`, `Lab9Backtracking.cpp` |
| Single-source shortest paths: Dijkstra and Bellman-Ford | `Lab11task1.cpp`, `Lab11task2.cpp` |
| Binary heaps (min and max) | `minheap.cpp`, `maxheap.cpp` |
| Counting with DP (painting fences) | `Painting_fences.cpp` |

Each file builds on its own:

```bash
g++ -std=c++17 -O2 Lab6.cpp -o lab6 && ./lab6
```
