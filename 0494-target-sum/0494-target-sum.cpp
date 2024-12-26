class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int N = nums.size();
        int total = 0;
        int zero_cnt = 0;
        sort(nums.begin(), nums.end());
        for(int number : nums){
            total += number;
            if(number == 0) zero_cnt++;
        }
        int minus = total - target;
        if(minus%2) return 0;
        minus /= 2;
        if(minus == 0) return 1*(1<<zero_cnt);
        if(minus<0) return 0;

        vector<vector<int>> dp(N-zero_cnt, vector<int>(minus+1));
        dp[0][0] = 1;
        if(nums[zero_cnt]<=minus) dp[0][nums[zero_cnt]] = 1;
        for(int i=zero_cnt; i<N-1; i++){
            for(int j=0; j<=minus; j++){
                dp[i-zero_cnt+1][j]+=dp[i-zero_cnt][j];
                if(j+nums[i+1]<=minus) dp[i-zero_cnt+1][j+nums[i+1]]+=dp[i-zero_cnt][j];
            }
        }


        return dp[N-zero_cnt-1][minus]*(1<<zero_cnt);
    }

};
/*
  0 1 2 
0 1 1 1 
1 1 2 2
2 0 1 2 
*/