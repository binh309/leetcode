#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int longestArithSeqLength(vector<int> &nums) {
    int n = nums.size();
    if (n <= 1) return n;

    // DP array: dp[i][diff] means the longest sequence ending at index i with difference diff
    vector<vector<int>> dp(n, vector<int>(1001, 1)); // 1001 to account for all possible diffs (-500 to 500)

    int ans = 2; // Minimum sequence length is 2 for a valid arithmetic sequence

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            int diff = nums[i] - nums[j] + 500; // Normalize difference to avoid negative index
            dp[i][diff] = dp[j][diff] + 1;
            ans = max(ans, dp[i][diff]);
        }
    }
    return ans;
}

int main() {
    vector<int> nums = {3, 6, 9, 12};
    cout << longestArithSeqLength(nums) << endl;  // Output: 4S
}
