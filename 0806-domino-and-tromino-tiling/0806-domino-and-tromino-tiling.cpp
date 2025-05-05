class Solution {
public:
    int numTilings(int n) {
        vector<vector<int>> ans(1001, vector<int>(3, 0));
        // ans[i] : 2 x i tile. ans[i][0] : upper tile filled, ans[i][1] : bottom tile filled, ans[i][2] : all tile filled
        ans[1][2] = 1;
        
        ans[2][0] = 1;
        ans[2][1] = 1;
        ans[2][2] = 2;

        for(int i=3; i<=n; i++){
            ans[i][0] = (1LL * ans[i-1][1] + ans[i-2][2]) % MOD;
            ans[i][1] = (1LL * ans[i-1][0] + ans[i-2][2]) % MOD;
            ans[i][2] = (1LL * ans[i-2][2] + ans[i-1][2] + ans[i-1][0] + ans[i-1][1]) % MOD;
        }
        return ans[n][2];
    }
private:
    const int MOD = 1e9 + 7;
};