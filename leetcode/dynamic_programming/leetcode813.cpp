#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

double largestSumOfAverages(vector<int>& nums, int k) {
    int n = nums.size();
    vector<vector<double>> dp(n + 1, vector<double>(k + 1, 0.0));
    vector<double> prefix_sum(n + 1, 0.0);

    // Compute prefix sums
    for (int i = 0; i < n; i++) {
        prefix_sum[i + 1] = prefix_sum[i] + nums[i];
    }

    // Base case: fill for 1 group
    for (int i = 1; i <= n; i++) {
        dp[i][1] = prefix_sum[i] / i; // Average of the whole segment from 0 to i-1
    }

    // Fill the DP table
    for (int k_count = 2; k_count <= k; k_count++) {
        for (int i = k_count; i <= n; i++) {
            for (int j = k_count - 1; j < i; j++) { // j is the end of the previous group
                double avg = (prefix_sum[i] - prefix_sum[j]) / (i - j); // Average of the current segment
                dp[i][k_count] = max(dp[i][k_count], dp[j][k_count - 1] + avg);
            }
        }
    }

    return dp[n][k];
}

int main() {
    vector<int> nums = {9, 1, 2, 3, 9};
    int k = 3;
    cout << largestSumOfAverages(nums, k) << endl; // Output should be the maximum sum of averages
    return 0;
}
