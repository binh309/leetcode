#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int count123;
    cin >> count123;
    if(count123==0){
        return 0;
    }
    vector<vector<int>> dp(count123,vector<int> (2,0));
    for(int i=0; i< count123;i++){
        cin >> dp[i][0]; cin >> dp[i][1];
    }
    sort(dp.begin(),dp.end(),[](vector<int> &a,vector<int> &b){
        return a[1]< b[1];
    });
    int ans=1;    
    int y=dp[0][1];
    for(int i=1 ;i< dp.size();i++){
        if(dp[i][0]>y){
            ans++;
            y=dp[i][1];
        }
    }
    cout << ans;
}