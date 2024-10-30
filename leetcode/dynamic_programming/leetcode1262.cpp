#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
int maxSumDivThree(vector<int>& nums) {
    int min_mod1 = 1e9, min2_mod1 = 1e9;
    int min_mod2 = 1e9, min2_mod2 = 1e9;
    int sum = 0;
    
    for (int num : nums) {
        sum += num;
        if (num % 3 == 1) {
            if (num < min_mod1) {
                min2_mod1 = min_mod1;
                min_mod1 = num;
            } else if (num < min2_mod1) {
                min2_mod1 = num;
            }
        } else if (num % 3 == 2) {
            if (num < min_mod2) {
                min2_mod2 = min_mod2;
                min_mod2 = num;
            } else if (num < min2_mod2) {
                min2_mod2 = num;
            }
        }
    }
    
    if (sum % 3 == 0) {
        return sum;
    } else if (sum % 3 == 1) {
        int option1 = (min_mod1 != 1e9) ? min_mod1 : 1e9;
        int option2 = (min_mod2 != 1e9 && min2_mod2 != 1e9) ? min_mod2 + min2_mod2 : 1e9;
        return sum - min(option1, option2);
    } else {
        int option1 = (min_mod2 != 1e9) ? min_mod2 : 1e9;
        int option2 = (min_mod1 != 1e9 && min2_mod1 != 1e9) ? min_mod1 + min2_mod1 : 1e9;
        return sum - min(option1, option2);
    }
}
int main(){
    vector<int> nums = {3,6,5,1,8};
    cout << maxSumDivThree(nums);
}