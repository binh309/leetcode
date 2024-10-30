#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
void solve(int n, int k, vector<int> &arr){
    vector<int> dp(arr.size(),1e9);
    dp[0]=0;
    for(int i=1 ;i <arr.size();i++){
        for(int j=1; j<=i;j++){
        	if(arr[j]==-1){
        		if(dp[i]=1e9){
        			dp[i]=-1;
				}
			}
			else{
				dp[i]=min(dp[i],dp[i-j]+arr[j]);
			}
        }
    }
    cout << dp[arr.size()-1] << endl;
    return;
}
int main(){
    int situation;
    cin >> situation;
    while(situation){
        int n,k;
        cin >> n >> k;
        vector<int> arr(k+1);
        for(int i=1 ;i <= k;i++){
        cin >> arr[i] ;
    	}
    	solve(n,k,arr);
        situation--;
    }
    return 0;
}