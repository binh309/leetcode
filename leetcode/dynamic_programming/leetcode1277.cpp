#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
int countSquares(vector<vector<int>>& matrix) {
    vector<int> dp(matrix[0].size(),0);
    int ans=0;
    for(int i=0 ;i< matrix.size();i++){
        for(int j=0 ; j< matrix[i].size();j++){
            if(matrix[i][j]!=0){
                dp[j]+=1;
                int min_value =1e9;
                int step=0;
                int h=j;
                while(h >=0 && matrix[i][h]!=0 ){
                    step+=1;
                    min_value=min(min_value, dp[h]);
                    if(min_value >=step){
                        ans+=1;
                    }
                    //cout << ans << " "
                    h--;
                }
                //cout << ans << " ";
            }
            else{
                dp[j]=0;
            }
            //cout << dp[j] << " ";
            //cout << ans << " ";
            //cout << endl;
        }
        //cout << endl;
    }
    return ans;   
}  
using namespace std;
    int main(){
        vector<vector<int>> matrix =
    {
        {0,1,1,1},
        {1,1,1,1},
        {0,1,1,1}
    };
    cout << countSquares(matrix);
}