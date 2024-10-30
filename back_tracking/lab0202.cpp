#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int shortest_route;  // To store the shortest route
vector<vector<vector<int>>> memo;  // Memoization table

void solve(vector<vector<int>> &dp, vector<bool> &visited, int places, int passengers_current, 
           int passengers, int index, int prev_index, int total_distance) {
    
    // If the current total distance exceeds the shortest route, prune this path
    if (total_distance >= shortest_route) {
        return;
    }

    // Memoization: If we already calculated this state, return
    if (memo[prev_index][passengers_current][index] != -1 && 
        memo[prev_index][passengers_current][index] <= total_distance) {
        return;
    }

    // Update the memo table for this state with the current minimum distance
    memo[prev_index][passengers_current][index] = total_distance;

    // If all passengers have been handled (either picked up or dropped off)
    bool all_visited = true;
    for (int i = 1; i < visited.size(); i++) {
        if (!visited[i]) {
            all_visited = false;
            break;
        }
    }
    if (all_visited) {
        // Return to depot from the last visited client
        shortest_route = min(shortest_route, total_distance + dp[prev_index][0]);
        return;
    }

    // Try to pick up or drop off passengers
    for (int i = 1; i < visited.size(); i++) {
        if (!visited[i]) {  // If passenger i is not visited yet
            if (i <= passengers && passengers_current + 1 <= places) {
                // Pick up passenger i
                visited[i] = true;
                solve(dp, visited, places, passengers_current + 1, passengers, index + 1, i, total_distance + dp[prev_index][i]);
                visited[i] = false;
            } else if (i > passengers && visited[i - passengers]) {
                // Drop off passenger i
                visited[i] = true;
                solve(dp, visited, places, passengers_current - 1, passengers, index + 1, i, total_distance + dp[prev_index][i]);
                visited[i] = false;
            }
        }
    }
}

int find_the_shortest_route(int passengers, int places, vector<vector<int>> &dp) {
    vector<bool> visited(dp.size(), false);  // To track visited clients
    shortest_route = INT_MAX;  // Reset for each test case
    
    // Initialize memoization table: 3D -> previous client, passengers on board, index
    memo.assign(dp.size(), vector<vector<int>>(places + 1, vector<int>(dp.size(), -1)));

    solve(dp, visited, places, 0, passengers, 0, 0, 0);  // Start from the depot
    return shortest_route;
}

int main() {
    int passengers, places;
    cin >> passengers >> places;
    
    // Initialize the distance matrix (2 * passengers + 1) x (2 * passengers + 1)
    vector<vector<int>> dp(passengers * 2 + 1, vector<int>(passengers * 2 + 1, 0));
    for (int i = 0; i < dp.size(); i++) {
        for (int j = 0; j < dp[i].size(); j++) {
            cin >> dp[i][j];
        }
    }

    cout << find_the_shortest_route(passengers, places, dp);
    return 0;
}
