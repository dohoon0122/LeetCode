class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> cnt(n*n, 0);
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cnt[grid[i][j]-1]++;
            }
        }

        vector<int> ans(2, 0);
        for(int i=0; i<n*n; i++){
            if(cnt[i]==2) ans[0] = i+1;
            else if(cnt[i]==0) ans[1] = i+1;
        }

        return ans;
    }
};