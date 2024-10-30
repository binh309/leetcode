#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
int check(string s, int index, int num_open, vector<vector<int>> &dp) {
    if (index == s.length()) {
        return num_open == 0; 
    }
    if (num_open < 0) {
        return 0;
    }
    if (dp[index][num_open] != -1) {
        return dp[index][num_open];
    }

    int ans = 0;
    if (s[index] == '*') {
        // Try treating '*' as '('
        ans |= check(s, index + 1, num_open + 1, dp);
        if(ans==1){
            return dp[index][num_open]=1;
        }
        // Try treating '*' as empty ''
        ans |= check(s, index + 1, num_open, dp);
         if(ans==1){
            return dp[index][num_open]=1;
        }
        // Try treating '*' as ')', only if we have unmatched '('
        if (num_open > 0) {
            ans |= check(s, index + 1, num_open - 1, dp);
        }
    }
    // If the current character is an opening parenthesis
    else if (s[index] == '(') {
        ans |= check(s, index + 1, num_open + 1, dp);
    }
    // If the current character is a closing parenthesis
    else if (s[index] == ')') {
        if (num_open > 0) {
            ans |= check(s, index + 1, num_open - 1, dp);
        } else {
            return dp[index][num_open] = 0;  // Invalid if no matching '('
        }
    }

    return dp[index][num_open] = ans;
}

bool checkValidString(string s) {
    vector<vector<int>> dp(s.length(), vector<int>(s.length(), -1)); 
    return check(s, 0, 0, dp);
}
int main(){
    string s = "(*))";
    cout << checkValidString(s);
}