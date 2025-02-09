class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long ans = 0;
        unordered_map<int, int> idx_diff; // {idx, }
        for(int i=0; i<nums.size(); i++){
            int diff = i - nums[i];
            int good_pairs = idx_diff[diff];
            ans += i - good_pairs;

            idx_diff[diff]++;
        }
        return ans;
    }
};