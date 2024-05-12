//
// Created by Marwan on 5/12/2024.
//

#include <bits/stdc++.h>
using namespace std;

// Returns count of ways to color k posts
long countWays(int n, int k)
{
    long dp[n + 1]; // To store results of subproblems using tabulation or bottom up approach
    memset(dp, 0, sizeof(dp)); // Initialize all entries as 0
    long long mod = 1000000007; // 10^9 + 7 is used for modulo operation when the result is too large
    // base cases

    dp[1] = k; // There are k ways to color first post
    dp[2] = k * k; // There are k*k ways to color first 2 posts

    for (int i = 3; i <= n; i++) {
        dp[i] = ((k - 1) * (dp[i - 1] + dp[i - 2])) % mod; // for all other cases we have k-1 choices * (dp[i-1] + dp[i-2])
    }

    return dp[n]; // return the result of the nth post or last post
}

// Returns count of ways to color k posts
// using k colors
// saves space
long countWaysOptimized(int n, int k)
{
    // There are k ways to color first post
    long total = k; // total ways to color the first post
    int mod = 1000000007; // 10^9 + 7 is used for modulo operation when the result is too large

    // There are 0 ways for single post to
    // violate (same color) and k ways to
    // not violate (different color)
    int same = 0, diff = k; // same is 0 and diff is k for the first post because there is no previous post to compare with

    // Fill for 2 posts onwards
    for (int i = 2; i <= n; i++) {
        // Current same is same as previous diff
        same = diff; // same is equal to diff because the previous post has different color

        // We always have k-1 choices for next post
        diff = (total * (k - 1)) % mod; // diff is total * (k-1) because we have k-1 choices for the next post


        // Total choices till i.
        total = (same + diff) % mod; // total is equal to same + diff because we have same choices + diff choices
    }

    return total; // return the total number of ways to color the posts
}


// Driver code
int main()
{
    // n is the number of posts and k is the number of colors
    int n = 3, k = 2;
    cout << countWays(n, k) << endl;
    return 0;
}
