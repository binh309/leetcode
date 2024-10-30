#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
int mod=1e9+7;
long long merge_and_count(vector<int> &arr, int left,int mid,  int right){
  long long ans=0;
  vector<int> arr_a; vector<int> arr_b;
  for(int i=left; i<= mid;i++){
    arr_a.push_back(arr[i]);
  }
  for(int i=mid+1;i <= right;i++ ){
    arr_b.push_back(arr[i]);
  }
  int index_a=0; int index_b=0; int size_a=mid-left+1; int size_b=right-mid;
  int index=left;
  while(index_a < size_a && index_b< size_b){
    if(arr_a[index_a] <= arr_b[index_b]){
    	//cout << arr_a[index_a] << " ";
      arr[index++]=arr_a[index_a++];
      //cout << arr_a[index_a];
    }
    else{
    	//cout << arr_b[index_b] << " ";
      arr[index++]=arr_b[index_b++];
      ans=(ans+size_a - index_a)%mod;
    }
  } 
  while(index_a < size_a){
  	//cout << arr[index] << " ";
  	arr[index++]=arr_a[index_a++];
  }
  while(index_b < size_b){
  	//cout << arr[index] << " ";
  	arr[index++]=arr_b[index_b++];
  }
  //cout << endl;
  return ans;

  
}
long long find_the_result(vector<int> &arr,int left, int right){
  if(left>=right){
    return 0;
  }
  int mid=(left+right)/2;
  long long sum_left=find_the_result(arr,left,mid);
  long long sum_right=find_the_result(arr,mid+1,right);
  long long sum=merge_and_count(arr,left,mid,right);
  return (sum+sum_left+sum_right)%mod;


}
int solve(vector<int> &arr){
  return find_the_result(arr,0,arr.size()-1);
}
int main(){
  int size;
  cin >> size;
  vector<int> arr(size);
  for(int i=0 ;i< size;i++){
    cin >> arr[i];
  }
  cout << solve(arr);
}