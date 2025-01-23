class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<int> rowCount(m, 0);
        vector<int> colCount(n, 0);

        for(int i = 0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]){
                    rowCount[j]++;
                    colCount[i]++;
                }
            }
        }

        int ans = 0;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]){
                    ans += (rowCount[j] > 1 || colCount[i] > 1);
                }
            }
        }

        return ans;       
    }
};