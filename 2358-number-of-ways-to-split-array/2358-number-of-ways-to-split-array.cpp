class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        vector<long long> prefix_sum(nums.size()+1);

        for(int i=0; i<nums.size(); i++){
            prefix_sum[i+1] = nums[i];
            prefix_sum[i+1] += prefix_sum[i];
        }

        int ans = 0;
        for(int i=0; i<nums.size()-1; i++){
            long long left = prefix_sum[i+1]; // nums[0]~nums[i]
            long long right = prefix_sum[nums.size()] - prefix_sum[i+1]; // nums[i+1] ~ nums[N-1]

            if(left >= right) ans++;
        }

        return ans;
    }
};