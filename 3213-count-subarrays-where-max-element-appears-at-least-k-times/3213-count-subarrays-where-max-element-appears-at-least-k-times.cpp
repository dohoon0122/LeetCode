class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int max_elem = *max_element(nums.begin(), nums.end());
        
        int left = 0;
        long long ans = 0; 
        int max_cnt = 0;
        for (int right = 0; right < nums.size(); right++) {
            if (nums[right] == max_elem) {
                max_cnt++;
            }
            while (max_cnt == k) {
                if (nums[left] == max_elem) {
                    max_cnt--;
                }
                left++;
            }
            ans += left;
        }
        return ans;
    }
};
