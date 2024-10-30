#include <iostream>
#include <vector>
#include <queue>
#include <bits/stdc++.h>
using namespace std;

int maxDistance(vector<vector<int>>& grid) {
    int n = grid.size();
    vector<vector<bool>> mst(n, vector<bool>(n, false));
    queue<pair<int, int>> que;
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] == 1) {
                mst[i][j] = true;
                que.push({i, j});
            }
        }
    }
    
    if (que.size() == 0 || que.size() == n * n) {
        return -1;
    }
    
    int idx[4] = {0, 0, -1, 1};
    int idy[4] = {-1, 1, 0, 0};
    int count = -1;
    
    while (!que.empty()) {
        ++count;
        int size = que.size();
        for (int i = 0; i < size; ++i) {
            auto [x, y] = que.front();
            que.pop();
            for (int j = 0; j < 4; ++j) {
                int x_new = x + idx[j];
                int y_new = y + idy[j];
                if (x_new >= 0 && x_new < n && y_new >= 0 && y_new < n && !mst[x_new][y_new]) {
                    que.push({x_new, y_new});
                    mst[x_new][y_new] = true;
                }
            }
        }
    }
    
    return count;
}

int main() {
    vector<vector<int>> grid = {{1, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    cout << maxDistance(grid);
}