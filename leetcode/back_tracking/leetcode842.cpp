#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
bool find_split_into_fibo(string num, int k, int index,vector<int> &arr){
    if(index==nums.size() && k>=3){
        return 1;
    }
    if(arr.size()==0 && nums[index]=='0'){
        arr.push_back(0);
        if(find_split_into_fibo(num,k+1,index+1,arr)){
            return true;
        }
        arr.pop_back();
    }
    if(arr.size()==1 && nums[index]=='0'){
        arr.push_back(0);
        if(find_split_into_fibo(num,k+1,index+1,arr)){
            return true;
        }
        arr.pop_back();
    }
    if(arr.size()>=2){
        int sum=arr[arr.size()-1]+arr[arr.size()-2];
        string tran=to_string(sum);
        for(int i=index ; i< nums.length();i++){
            if(tran[i-index]!=nums[i]){
                return false;
            }
        }
        arr.push_back(sum);
        if(find_split_into_fibo(num,k+1,index+tran.length(),arr)){
            return true;
        }
        arr.pop_back();
        return false;
    }
    for(int i=1; i <=min( num.length()/3,9) && index+i < num.size(); i++){
        if(arr.size()==0 || arr.size()==1){
            string ans=num.substr(index, i);
            int k=stoi(ans);
            arr.push_back(k);
            if(find_split_into_fibo(num,k+1,index+i,arr)){
                return true;
            }
            arr.pop_back();
        }
    }
    return false;


}
vector<int> splitIntoFibonacci(string num) {
    vector<int> arr;
    if(find_split_into_fibo(num,0,0,arr)){
        return arr;
    }
    return {};
}
int main(){
    string num = "1101111";
    vector<int> result=splitIntoFibonacci(num);
}