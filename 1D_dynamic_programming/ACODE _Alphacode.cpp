#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
void solve(string input){
    vector<int> dp(input.length()+1,0);
    if(input[input.length()-1]!='0'){
    	dp[input.length()-1]=1;
	}
	dp[input.length()]=1;
	for(int i=input.length()-2 ;i>=0; i--){
		if(input[i] =='0' && input[i+1]=='0'){
			cout << "-1" << endl;
			return ;
		}
		if(input[i+1]=='0' && input[i]>'2'){
			cout << "-1" << endl;
		}
		if(input[i]=='0'){
			continue;
		}
		if(input[i+1]=='0'){
			dp[i]=dp[i+2];
		}
		else if(stoi(input.substr(i,2))<=26){
			dp[i]=dp[i+1]+dp[i+2];
		}
		else{
			dp[i]=dp[i+1];
		}
	}
	cout << dp[0] << endl;
	return ;
}
int main(){
    while(1){
        string input;
    	cin >> input;
    	if(input=="0"){
    		break;
		}
    	solve(input);
    }
    return 0;
}