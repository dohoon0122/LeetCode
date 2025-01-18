class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int n, m;
        m = grid.size();
        n = grid[0].size();

        vector<pair<int, int>> dir = {{0, 0}, {0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        queue<pair<int, int>> curr;
        queue<pair<int, int>> prev;
        vector<vector<int>> cost(m, vector<int>(n, INT_MAX));

        cost[0][0] = 0;
        int curr_cost = 0;
        curr.push({0, 0});

        int order;
        bool found = false;

        while(!found){
            while(!curr.empty()){
                auto [row, col] = curr.front();
                if(row==m-1 && col==n-1){
                    found = true;
                    break;
                }
                curr.pop();
                prev.push({row, col});

                order = grid[row][col];
                int n_row, n_col;
                n_row = row + dir[order].first;
                n_col = col + dir[order].second;
                if(0<=n_row && n_row<m && 0<=n_col && n_col<n && cost[n_row][n_col] > curr_cost){
                    curr.push({n_row, n_col});
                    cost[n_row][n_col] = curr_cost;
                }
            }
            curr_cost++;
            while(!prev.empty()){
                auto [row, col] = prev.front();
                if(row==m-1 && col==n-1){
                    found = true;
                    break;
                }
                prev.pop();

                for(int i=1; i<5; i++){
                    auto [dr, dc] = dir[i];
                    int n_row = row + dr;
                    int n_col = col + dc;
                    if(0<=n_row && n_row<m && 0<=n_col && n_col<n && cost[n_row][n_col] > curr_cost){
                        curr.push({n_row, n_col});
                        cost[n_row][n_col] = curr_cost;
                    }
                }
            }
        }
        
        return cost[m-1][n-1];
    }
};