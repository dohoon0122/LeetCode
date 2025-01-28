class Solution {
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> visited(n, vector<bool>(m, false));
        queue<pair<int, int>> q;
        vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

        int ans = 0;
        int temp = 0;;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(visited[i][j]) continue;
                if(grid[i][j]==0){
                    visited[i][j] = true;
                    continue;
                }
                temp = 0;
                q.push({i, j});
                visited[i][j] = true;
                while(!q.empty()){
                    auto [row, col] = q.front();
                    temp += grid[row][col];
                    q.pop();
                    for(auto [dr, dc]: dir){
                        int n_row = row + dr;
                        int n_col = col + dc;
                        if(0<=n_row && n_row<n && 0<=n_col && n_col<m && !visited[n_row][n_col]){
                            visited[n_row][n_col] = true;
                            if(grid[n_row][n_col]==0) continue;
                            q.push({n_row, n_col});
                        }
                    }
                }
                ans = max(ans, temp);
            }
        }
        return ans;
    }
};