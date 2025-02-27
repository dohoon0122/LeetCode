class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        int ans = 0;

        vector<vector<int>> dp(n, vector<int>(n, 0));

        unordered_map<int, int> val_to_idx;
        for(int i=0; i<n; i++){
            val_to_idx[arr[i]] = i;
            for(int j=0;j<i; j++){
                int d = arr[i]-arr[j];
                int prev = val_to_idx.count(d)?val_to_idx[d]:-1;
                if(d<arr[j] && prev>=0) dp[j][i] = dp[prev][j] + 1;
                else dp[j][i] = 2;

                ans = max(ans, dp[j][i]);
            }
        }

        return ans>2?ans:0;
    }
};