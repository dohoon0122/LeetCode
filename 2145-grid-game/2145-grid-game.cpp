class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();
        long long sum1 = 0, sum2 = 0;
        for(int i=0; i<n; i++){
            sum1 += grid[0][i];
        }

        long long min_sum = LONG_LONG_MAX;
        for(int i=0; i<n; i++){
            sum1 -= grid[0][i];
            min_sum = min(min_sum, max(sum1, sum2));
            sum2 += grid[1][i];
        }

        return min_sum;
    }
};