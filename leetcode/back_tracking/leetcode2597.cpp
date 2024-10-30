#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
int subset_count;
void find_total_subset(vector<int> &dp, vector<int> &nums, int k, int index) {
	if(dp.size()>0){
		subset_count++;
	}
    if (index >= nums.size()) {
       	//subset_count++;
        return;
    }
    for (int i = index; i < nums.size(); i++) {
        if (dp.empty()) {
            dp.push_back(nums[i]);
            find_total_subset(dp, nums, k, i + 1);
            dp.pop_back();
        } else {
            if (binary_search(dp.begin(), dp.end(), nums[i] - k) == 0) {
                dp.push_back(nums[i]);
                find_total_subset(dp, nums, k, i + 1);
                dp.pop_back();
            }
        }
    }
}

int beautifulSubsets(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    vector<int> dp;
    subset_count = 0;
    find_total_subset(dp, nums, k, 0);
    // Subtract 1 to exclude the empty subset
    return subset_count ;
}
int main(){
    vector<int> nums = {2,4,6};
    int k = 2;
    cout << beautifulSubsets(nums,k);
}