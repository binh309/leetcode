#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n=5;
    vector<int> arr={2,2,3,2,2};
    vector<int> dp(n,0);
    dp[0]=arr[0];
    dp[1]=arr[1];
    dp[2]=arr[2];
    for(int i=3; i<dp.size();i++){
        dp[i]=arr[i]+min(dp[i-1],min(dp[i-2],dp[i-3]));
        //cout << dp[i] << " ";
    }
    cout << min(dp[n-1],min(dp[n-2],dp[n-3]));
    return 0;
}