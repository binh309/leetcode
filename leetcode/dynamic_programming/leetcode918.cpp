#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
int maxSubarraySumCircular(vector<int>& nums) {
    if(nums.size()==0){
        return nums[0];
    }
    vector<int> dp_left(nums.size(),0);
    vector<int> dp_right(nums.size()+1,0);
    int ans=-1e9;
    dp_left[0]=nums[0];
    dp_right[nums.size()-1]=nums[nums.size()-1];
    int value=0; int prev=nums[0];
    int sum=nums[0];
    for(int i=1; i< nums.size();i++){
        value=max(nums[i],prev+nums[i]);
        sum+=nums[i];
        dp_left[i]=max(sum,dp_left[i-1]);
        //dp_left[i]=max(nums[i],dp_left[i-1]+nums[i]);
        ans=max(ans,value);
        prev=value;
    }
    sum=nums[nums.size()-1];
    for(int i=nums.size()-2;i>=0;i--){
        sum+=nums[i];
        dp_right[i]=max(dp_right[i+1],sum);
        //cout << save[i] << " ";
    }
    for(int i=0; i< nums.size();i++){
        ans=max(ans,dp_left[i]+dp_right[i+1]);
        //cout << dp_left[i]+save[i+1] << endl;
    }

    return ans;  
}
int main(){
    vector<int> nums = {1,-2,3,-2};
    cout << maxSubarraySumCircular(nums);
}