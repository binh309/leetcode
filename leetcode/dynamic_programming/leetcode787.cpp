#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
 int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k) {
    vector<bool> mst(n,false);
    vector<vector<int>> graph(n,vector<int> (n,0));
    for(int i=0; i< flights.size();i++){
        int scoure=flights[i][0]; int destination=flights[i][1]; int prices=flights[i][2];
        graph[scoure][destination]=prices;
    }
    vector<vector<int>> save(k+2,vector<int> (n,1e9));
    save[0][src]=0;
    for(int count=1; count<=k+1;count++){
    	int min_value=1e9;
    	int min_index=src;
    	save[count]=save[count-1];
        for(int i=0 ; i< n;i++){
        	if(mst[i]==false && save[count-1][i]!=1e9){
        		//cout << i << " ";
        		for(int j=0; j< graph[i].size();j++){
        			if(graph[i][j]!=0){
        				save[count][j]=min(save[count][j],graph[i][j]+save[count-1][i]);
        				if(min_value> save[count][j]){
        				min_value=save[count][j];
        				if(save[count][j]==graph[i][j]+save[count-1][i]){
        					min_index=i;
						}
						else{
							min_index=j;
						}
					}
					}
				}
			}
		}
		mst[min_index]=true;
    }
    if(save[k+1][dst]==1e9){
        return -1;
    }
    return save[k+1][dst];
}
int main(){
    int n = 4;
    vector<vector<int>> flights = {{0,1,100} ,{1,2,100},{2,0,100},{1,3,600},{2,3,200}};
    int  src = 0, dst = 3, k = 1;
    cout << findCheapestPrice(n,flights,src,dst,k);
}