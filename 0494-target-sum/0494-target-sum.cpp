class Solution {
public:
    int ans;

    int findTargetSumWays(vector<int>& nums, int target) {
        int N = nums.size();
        int total = 0;
        int zero_cnt = 0;
        for(int number : nums){
            total += number;
            if(number == 0) zero_cnt++;
        }

        sort(nums.begin(), nums.end());

        int minus = total - target;
        if(minus%2) return 0;
        minus /= 2;

        ans = 0;
        backtrack(zero_cnt, N, nums, 0, minus);

        cout<<minus<<" "<<zero_cnt<<"\n";

        return ans*(1<<zero_cnt);
    }

    void backtrack(int idx, int N, vector<int>& nums, int curr, int target){
        if(curr > target) return;
        if(curr == target){
            ans++;
            return;
        }
        if(idx >= N) return;

        backtrack(idx+1, N, nums, curr + nums[idx], target);
        backtrack(idx+1, N, nums, curr, target);
    }
};