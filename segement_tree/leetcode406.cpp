#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
struct segment_tree{
    int size;
    vector<int> st;
    void init(int n){
        this->size=n;
        st.resize(4*n,0);
        return;
    }
    void build(vector<int> &v, int node , int begin, int end){
        
    }
    void build(vector<int> &v){
        build(v, 0,0, size-1);
    }
}
vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {

}
int main(){
    vector<vector<int>> people = {{7,0},{4,4},{7,1},{5,0},{6,1},{5,2}};
    vector<vector<int>> result=reconstructQueue(people);
    
    
    return 0;
}