class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        // dp[i] : i-length good string
        vector<int> dp(high+1, 0);
        int MOD = 1e9+7;
        dp[one]++;
        dp[zero]++;

        int ans = 0;
        for(int i=0; i<=high; i++){
            if(i>zero) dp[i] += dp[i-zero];
            if(i>one) dp[i] += dp[i-one];
            dp[i]%=MOD;
            if(i>=low){
                ans+=dp[i];
                ans%=MOD;
            }
        }

        return ans;
    }
};