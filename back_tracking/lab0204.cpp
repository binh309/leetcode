#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
bool check(vector<vector<int>> &puzzle,int row1, int col1, int row2, int col2){
    for(int i=0; i< puzzle.size();i++){
        int x1=puzzle[i][0]; int y1=puzzle[i][1]; int x2=puzzle[i][2]; int y2=puzzle[i][3];
        if((x1 <=row1 && row1 <=x2) || (x1<=row2 && row2 <=x2)){
            if((y1<=col1 && col1<=y2) || (y1<=col2 && col2 <=x2) ){
                return false;
            }
        }
    }
    return true;
}
bool solve(vector<vector<int>> &dp,int index, vector<vector<int>> &puzzle, int row, int col){
    if(index==dp.size()){
        return 1;
    }
    int row_current=dp[index][0]; int col_current=dp[index][1];
    if(row-row_current+1>=0 && col-col_current+1>=0){
        for(int i=0; i<row-row_current+1;i++){
            for(int j=0; j< col-col_current+1;j++){
                if(check(puzzle,i,j,i+row_current,j+col_current)){
                    puzzle[index].push_back(i); puzzle[index].push_back(j);
                    puzzle[index].push_back(i+row_current); puzzle[index].push_back(j+col_current);
                    if(solve(dp,index+1,puzzle,row,col)){
                        return true;
                    }
                    else{
                        puzzle[index].pop_back(); puzzle[index].pop_back(); 
                        puzzle[index].pop_back(); puzzle[index].pop_back();
                    }
                }
            }
        }
    }
    if(row-col_current+1>=0 && col-row_current+1>=0){
        for(int i=0; i<row-col_current+1;i++){
            for(int j=0; j< col-row_current+1;j++){
                if(check(puzzle,i,j,i+col_current,j+row)){
                    puzzle[index].push_back(i); puzzle[index].push_back(j);
                    puzzle[index].push_back(i+col_current); puzzle[index].push_back(j+row_current);
                    if(solve(dp,index+1,puzzle,row,col)){
                        return true;
                    }
                    else{
                        puzzle[index].pop_back(); puzzle[index].pop_back(); 
                        puzzle[index].pop_back(); puzzle[index].pop_back();
                    }
                }
            }
        }
    }
    return false;
}

int check_the_rec(vector<vector<int>> &dp,int row,int col, int number_recs){
    vector<vector<int>> puzzle(number_recs);
    return solve(dp,0,puzzle,row,col);
}
int main(){
	int row; int col;
	cin >> row >> col;
	int number_recs;
	cin >> number_recs;
    vector<vector<int>> dp(number_recs,vector<int> (2));
    for(int i=0 ;i< number_recs;i++){
        int row_rec; int col_rec;
        cin >> row_rec >> col_rec;
        dp[i][0]=row_rec; dp[i][1]=col_rec;
    }
    cout << check_the_rec(dp,row,col,number_recs);
}