class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        vector<int> arr(400002, 0); 
        int offset = 200000; 

        for (int num : nums) {
            arr[num - k + offset]++; 
            arr[num + k + 1 + offset]--; 
        }

        int ans = 0, current = 0;
        for (int count : arr) {
            current += count;
            ans = max(ans, current);
        }

        return ans;
    }
};