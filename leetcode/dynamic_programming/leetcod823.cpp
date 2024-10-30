#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
int mod=1e9+7;
int numFactoredBinaryTrees(vector<int>& arr) {
    sort(arr.begin(),arr.end());
    unordered_map<int, int> Map;
    for(int i=0; i< arr.size();i++){
        Map[arr[i]]=i;
    }
    vector<int> dp(arr.size(),1);
    for(int i=0; i< arr.size();i++){
        for(int j=0; j< i;j++){
            if(arr[i]%arr[j]==0){
                int k=arr[i]/arr[j];
                if(Map.find(k)!=Map.end()){
                    int location=Map[k];
                    dp[i]=(1ll*dp[i]+1ll*dp[j]*dp[location])%mod;
                }
            }
        }
    }
    int sum=0;
    for(int i=0; i< arr.size();i++){
        //cout << dp[i] << " ";
        sum=(1ll*sum+1ll*dp[i])%mod;
    }
    //cout << endl;
    return sum;
}
int main(){
    vector<int > arr = {2,4,5,10};
    cout << numFactoredBinaryTrees(arr);
    return 0;
}