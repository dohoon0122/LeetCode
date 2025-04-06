class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
                   

        sort(nums.begin(), nums.end());
  
        vector<int> dp(n, 0); 
        int subset_size = -1;
        int max_subset_size = -1;
        int max_subset_idx = -1;
        for(int i=0; i<n; i++)
        {
            subset_size = 0;
            for(int j=0; j<i; j++)
            {
                if(nums[i]%nums[j]==0 && subset_size < dp[j]) subset_size = dp[j];
            }
            dp[i] = subset_size + 1;

            if(max_subset_size < dp[i])
            {
                max_subset_size = dp[i];
                max_subset_idx = i;
            }
        }
        vector<int> ans;
        subset_size = max_subset_size;
        int subset_tail = nums[max_subset_idx];
        for(int i=max_subset_idx;i>=0;i--){
            if(subset_size == 0) break;

            if(subset_tail%nums[i]==0 && subset_size == dp[i]){
                ans.push_back(nums[i]);
                subset_tail = nums[i];
                subset_size--;
            } 
        }
        return ans;
    }
};