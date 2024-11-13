class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        long long count = 0;
        int n = nums.size();

        for (int i = 0; i < n - 1; ++i) {
            int low = lower - nums[i];
            int high = upper - nums[i];
            auto low_it = lower_bound(nums.begin() + i + 1, nums.end(), low);
            auto high_it = upper_bound(nums.begin() + i + 1, nums.end(), high);
            count += distance(low_it, high_it);
        }

        return count;
    }
};