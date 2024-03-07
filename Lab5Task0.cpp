#include <iostream>
#include <cmath>

using namespace std;

// Function to count the number of digits in a number
// Returns the count of digits
int digitsize(int x, int &operations) { // O(N)
    int count = 0;
    operations++; // Counting the operation
    while (x >= 1) {
        count++; // Incrementing count for each digit
        x = x / 10; // Removing the last digit
        operations += 2; // Counting division and assignment operations
    }
    operations++; // Counting the last iteration
    return count;
}

// Recursive function to perform integer multiplication
// Returns the product of two integers
int multiply(int x, int y, int &operations) {
    if (x < 10 && y < 10) { // Base case: if both numbers are single digits
        operations += 3; // Counting the comparison and multiplication operations
        return x * y; // Simply multiply them
    }

    // Determine the size of numbers by counting digits
    int x_size = digitsize(x, operations);// O(N)
    int y_size = digitsize(y, operations);// O(N)
    int n = max(x_size, y_size); // Get the maximum size O(1) complexity
    operations++; // Counting the assignment operation

    int m = (n + 1) / 2; // Splitting point (accounting for even and odd numbers)
    operations++; // Counting the addition and division operations

    int z = int(pow(10, m)); // Getting the power that will be used ahead O(1)
    operations++; // Counting the exponentiation operation

    // Splitting the numbers into halves
    int a = x / z;
    int b = x % z;
    int c = y / z;
    int d = y % z;
    operations += 4; // Counting the division and modulo operations

    // Recursive calls to perform multiplication
    int ac = multiply(a, c, operations); // Recursively compute a * c
    int bd = multiply(b, d, operations); // Recursively compute b * d
    int sum = multiply(a + b, c + d, operations); // Recursively compute (a + b) * (c + d)
    int trick = sum - bd - ac; // Intermediate result
    int product = ac * pow(10, 2 * m) + trick * z + bd; // Final result
    operations += 3; // Counting the multiplication, addition, and assignment operations

    return product;

    // we call the multiply function thrice therefore we have 3T(N), and the digit counting function is O(N) so we get 3T(N) + N
}

int main() {
    // Test cases
    int operations = 0;
    cout << "Test case 1: 17 x 22 : " << multiply(17, 22, operations) << " | " << operations << " operations" << endl;
    operations = 0;
    cout << "Test case 3: 112925 x 422 : " << multiply(112925, 422, operations) << " | " << operations << " operations" << endl;
    operations = 0;
    cout << "Test case 2: 22223 x 501 : " << multiply(22223, 501, operations) << " | " <<operations << " operations" << endl;
    return 0;
}
