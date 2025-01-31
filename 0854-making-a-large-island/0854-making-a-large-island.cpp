class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        n = grid.size();
        unordered_map<int, int> island_size;
        int island_id = 2;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1){
                    island_size[island_id] = bfs(i, j, island_id, grid);
                    island_id++;
                }
            }
        }

        int ans = 0;
        for(auto [key, val]: island_size){
            ans = max(ans, val);
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 0){
                    set<int> id_set;
                    for(auto [dr, dc]: dir){
                        int n_row = i + dr;
                        int n_col = j + dc;
                        if(0<=n_row && n_row<n && 0<=n_col && n_col<n && grid[n_row][n_col]>1){
                            id_set.insert(grid[n_row][n_col]);
                        }
                    }
                    int new_size = 1;
                    for(auto id: id_set){
                        new_size += island_size[id];
                    }
                    ans = max(ans, new_size);
                }
            }
        }

        return ans;
    }
    int bfs(int r, int c, int id, vector<vector<int>>& grid){
        queue<pair<int, int>> q;
        q.push({r, c});
        grid[r][c] = id;
        int size = 1;
        while(!q.empty()){
            auto [row, col] = q.front();
            q.pop();
            for(auto [dr, dc]: dir){
                int n_row = row + dr;
                int n_col = col + dc;
                if(0<=n_row && n_row<n && 0<=n_col && n_col<n && grid[n_row][n_col] == 1){
                    grid[n_row][n_col] = id;
                    q.push({n_row, n_col});
                    size+=1;
                }
            } 
        }
        return size;
    }

private: 
    vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int n;
};