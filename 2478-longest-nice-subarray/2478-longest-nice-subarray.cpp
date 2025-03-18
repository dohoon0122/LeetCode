class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int curr = 0, ans = 0, left = 0;
        for(int right=0; right<nums.size(); right++){
            while((curr & nums[right])!=0){
                curr^=nums[left];
                left++;
            }
            curr |= nums[right];
            ans = max(ans, right-left+1);
        }

        return ans;
    }
};