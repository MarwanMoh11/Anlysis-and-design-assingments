#include <iostream>
#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>
#include <cmath>
#include <limits>

using namespace std;



// Structure to represent a point in 2D plane
struct Point {
    int x, y;
};
// Custom comparison function for sorting Points based on x-coordinate
bool compareX(const Point& a, const Point& b) {
    return a.x < b.x;
}
// Custom comparison function for sorting Points based on y-coordinate
bool compareY(const Point& a, const Point& b) {
    return a.y < b.y;
}

// Function to calculate the Euclidean distance between two points
double dist(const Point& p1, const Point& p2) {
    // Function to calculate the Euclidean distance between two points
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));

}

// Function to find the closest pair of points among a strip of points
double stripClosest(vector<Point> strip, double d) {
    double minDist = d;

    // Sort the strip based on y-coordinate
    sort(strip.begin(), strip.end(), compareY);

    // Iterate through each point in the strip
    for (size_t i = 0; i < strip.size(); ++i) {
        // Compare each point with its neighbors within a distance of d
        for (size_t j = i + 1; j < strip.size() && (strip[j].y - strip[i].y) < minDist; ++j) {
            // Update minDist if a closer pair is found (Insert code here)

        }
    }

    return minDist;
}

// Function to find the closest pair of points using a divide and conquer approach
double closestUtil(const vector<Point>& points, int left, int right) {
    // Base case: If there are 2 or 3 points, use brute force method
    if (right - left <= 3) {
        double minDist = numeric_limits<double>::max();
        for (int i = left; i <= right; ++i) {
            for (int j = i + 1; j <= right; ++j) {
                minDist = min(minDist, dist(points[i], points[j]));
            }
        }
        return minDist;
    }

    // Find the middle point
    int mid = (left + right) / 2;

    // Recursively find the closest pair in left and right halves
    double dl = closestUtil(points, left, mid);
    double dr = closestUtil(points, mid + 1, right);

    // Find the minimum of dl and dr = d
    double d = min(dl, dr);

    // Create a strip containing points within d distance of the middle line
    vector<Point> strip;
    for (int i = left; i <= right; i++) {
        if (abs(points[i].x - points[mid].x) < d) {
            strip.push_back(points[i]);
        }
    }

    // Sort the strip by y coordinate
    sort(strip.begin(), strip.end(), compareY);

    // Find the closest pair in the strip and return the minimum distance
    return min(d, stripClosest(strip, d));
}


// Function to find the closest pair of points
double closestPair(const vector<Point>& points) {
    // Sort points based on x-coordinate
    vector<Point> sortedPoints = points;
    sort(sortedPoints.begin(), sortedPoints.end(), compareX);

    // Call the recursive function to find the closest pair
    return closestUtil(sortedPoints, 0, sortedPoints.size() - 1);
}


using namespace std;

struct bucket{
    int id;
    bool full;

};

// requires the array to be sorted
int storage(bucket arr[],int start, int end){
    if(arr[end].full == 0){
        return 0;
    }
    if(arr[start].full == 1){
        return (end+1-start);

    } else if (arr[start].full == 0){
            return storage(arr, start, start+(end-start)/2) + storage(arr, (start+(end-start)/2)+1, end);} else {



    }



}

int maxhelper(int arr[], int s, int e) {
    // initialization takes constant time
    int sum = 0;
    int left = INT_MIN;
    int right = INT_MIN; // Fix: Initialize right to INT_MIN instead of INT_MAX
    int middle = (s + e) / 2;

    // each for loop takes n/2 so n/2 + n/2 = n so O(n)
    for (int i = middle + 1; i <= e; i++) { // Fix: Change the loop condition to <= instead of >=
        sum += arr[i];
        right = std::max(right, sum); // Fix: Change left to right
    }

    sum = 0; // Reset sum for the next loop

    for (int i = middle; i >= s; i--) {
        sum += arr[i];
        left = std::max(left, sum); // Fix: Change right to left
    }

    return left + right;
}

int max(int arr[], int s, int e) {
    if (s == e) {
        return arr[s];
    }

    int middle = (s + e) / 2;
    int maxleft = max(arr, s, middle);
    int maxright = max(arr, middle + 1, e);
    int maxoverlap = maxhelper(arr, s, e);

    return std::max({maxleft, maxright, maxoverlap}); // Fix: Use std::max to find the maximum of three values
}






int main(){
    bucket arr[] = {{11,1},
                    {12,0},
                    {13,0},
                    {14,0},
                    {15,0},
                    {16,1}
    };

    sort(begin(arr),end(arr),[](const bucket &s, const bucket &e){return s.full < e.full;});

    cout << storage(arr,0,5);

    cout << endl;




    int arr2[10] = {100,90,-80,60,40,-100,30,20,-10,0};
    cout << max(arr2, 0, 9);


    cout << endl;

    // Example usage
    vector<Point> points1 = {{2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}};  //min dist bet. (2,3),(3,4)
    cout << "Minimum distance between two points: " << closestPair(points1) << endl;// Expected output: 1.41421

    vector<Point> points2 = {{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}, {6, 6}}; //The points are arranged diagonally, so the minimum distance is between any two consecutive points.
    cout << "Minimum distance between two points: " << closestPair(points2) << endl;// Expected output: 1.41421

    vector<Point> points3 = {{100, 200}, {300, 400}, {500, 600}, {700, 800}, {900, 1000}, {1100, 1200}}; //The points are arranged diagonally with a consistent difference of 200 in both x and y coordinates
    cout << "Minimum distance between two points: " << closestPair(points3) << endl; // Expected output: 282.843

    vector<Point> points4 = {{-10, -10}, {10, 10}, {-20, -20}, {20, 20}, {-30, -30}, {30, 30}}; //The points are arranged diagonally
    cout << "Minimum distance between two points: " << closestPair(points4) << endl; // Expected output: 14.1421

    vector<Point> points5 = {{-10, 10}, {10, 1}, {-2, -20}, {25, 10}, {-30, -10}, {32, 3}}; //The points are arranged randomly
    cout << "Minimum distance between two points: " << closestPair(points5) << endl; // Expected output: 9.89949 //min dist bet. (25,10),(32,3)

    return 0;
}

