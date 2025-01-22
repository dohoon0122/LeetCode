class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        int n = isWater.size();
        int m = isWater[0].size();

        vector<vector<int>> ans(n, vector<int>(m, -1));

        queue<pair<int, int>> q;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(isWater[i][j]){
                    q.push({i, j});
                    ans[i][j] = 0;
                }
            }
        }

        int curr_h = 1;
        while(!q.empty()){
            int temp = q.size();

            for(int i=0; i<temp; i++){
                auto [row, col] = q.front();
                q.pop();

                for(auto [dr, dc]: dir){
                    int n_row = row + dr;
                    int n_col = col + dc;

                    if(0<=n_row && n_row<n && 0<=n_col && n_col<m && ans[n_row][n_col] == -1){
                        ans[n_row][n_col] = curr_h;
                        q.push({n_row, n_col});
                    }
                }
            }
            curr_h++;
        }

        return ans;
    }
};