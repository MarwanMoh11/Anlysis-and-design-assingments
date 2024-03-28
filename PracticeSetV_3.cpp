#include <iostream>
#include <vector>
using namespace std;

bool subexist(vector<int>& A, int target){
    vector<std::vector<bool>> dp(A.size() + 1, vector<bool>(target + 1, false));

    for (int i = 0; i < A.size() + 1; i++){
        dp[i][0] = true;
    }


    for (int i = 1; i < target + 1; i++){
        dp[0][i] = false;
    }



    for (int i = 1; i < A.size() + 1; i++){

        for (int j = 1; j < target + 1; j++){

            if (A[i-1] > j){

                    dp[i][j] = dp[i-1][j];
            } else if (A[i-1] == j){

                dp[i][j] = true;
            } else {

                dp[i][j] = dp[i-1][j] || dp[i-1][j - A[i-1]];
            }
        }
    }

    return dp[A.size()][target];

}

int GCD(int a, int b){
    if (b == 0){
        return a;
    }
return GCD(b, a % b);
}

int findmincrops(int l, int w){
    int x = GCD(l, w);
    int mincrops = (l * w) / (x * x);
return mincrops;
}



int getPeakPeriodLength(const vector<int>& dailyCases) {
    int highestperiod = 1;
    int max = dailyCases[0];

    for (int i = 1; i < dailyCases.size(); i++) {


        if (dailyCases[i] == max) {
            highestperiod++;
        } else if (dailyCases[i] > max) {
            max = dailyCases[i];
            highestperiod = 1;
        }

    }

    return highestperiod;
}



int main() {
    std::vector<int> A = {3, 34, 4, 12, 5, 2};
    int K = 9;
    if (subexist(A, K))
        std::cout << "Subset with sum " << K << " exists.\n";
    else
        std::cout << "No subset with sum " << K << " exists.\n";



    int l, w;
    cout << "Enter the length and width of the piece of land: ";
    cin >> l >> w;
    int minCrops = findmincrops(l, w);
    cout << "Minimum number of crops needed to manage: " << minCrops << std::endl;
    return 0;

}