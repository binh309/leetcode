#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
bool canIWin(int maxChoosableInteger, int desiredTotal) {
    if(maxChoosableInteger>=desiredTotal){
        return true;
    }
    for(int i=1 ;i<=maxChoosableInteger;i++){
        int total=i;    bool ans= true;
        while(total > desiredTotal){
            total+=maxChoosableInteger+1;
            ans=!ans;
        }
        if(ans==true){
            return true;
        }
    }
    return false;
}
int main(){
	int maxChoosableInteger = 10;
	int desiredTotal = 11;
    cout << canIWin(maxChoosableInteger,desiredTotal);
}