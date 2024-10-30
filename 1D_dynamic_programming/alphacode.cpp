#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
int main(){
    string input="1111111111";
    vector<int> dp(input.length(),0);
    dp[input.length()-2]=2;
    if(input[input.length()-1]!='0'){
        dp[input.length()-1]=1;
    }
    else{
        if(input[input.length()-2]=='1' || input[input.length()-2]=='2'){
            dp[input.length()-2]=1;
        }
    }
    for(int i=dp.size()-3 ;i>=0; i--){
       
        if(stoi(input.substr(i,2))<=26){
            dp[i]=dp[i+1]+dp[i+2];
        }
        else{
            dp[i]=dp[i+1];
        }
        //cout << dp[i] << " ";
    }
    cout << dp[0] << endl;
    
}