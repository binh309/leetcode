#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
int longestMountain(vector<int>& arr) {
    if(arr.size()<=2){
        return 0;
    }
    vector<int> dp_left(arr.size(),1);
    vector<int> dp_right(arr.size(),1);
    for(int i=1; i< arr.size();i++){
        if(arr[i]>arr[i-1]){
            dp_left[i]=dp_left[i-1]+1;
        }
    }
    for(int i=arr.size()-2;i>=0; i--){
        if(arr[i]>arr[i+1]){
            dp_right[i]=dp_right[i+1]+1;
        }
    }
    int ans=0;
    for(int i=0; i<arr.size();i++){
        if(dp_left[i]!=1 && dp_right[i]!=1){
            ans=max(ans,dp_left[i]+dp_right[i]);
        }
    }
    if(ans-1<3){
        return 0;
    }
    return ans-1;
}
int main(){
    vector<int> arr = {2,1,4,7,3,2,5};
    cout << longestMountain(arr);
}