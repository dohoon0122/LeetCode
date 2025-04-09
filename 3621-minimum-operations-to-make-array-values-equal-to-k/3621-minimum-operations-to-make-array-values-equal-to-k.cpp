class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        if (k>nums[0]) return -1;
        
        int idx = n-1;
        int ans = 0;
        int current = nums[n-1];
        while(current>nums[0])
        {
            idx--;
            if(nums[idx]!=current)
            {
                ans++;
                current = nums[idx];
            }
        }
        if(nums[0]!=k) ans++;
        return ans;
    }
};