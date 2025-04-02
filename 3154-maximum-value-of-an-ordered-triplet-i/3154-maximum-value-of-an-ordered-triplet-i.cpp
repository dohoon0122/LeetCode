class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> leftMax(n), rightMax(n);
        for(int i=1;i<n;i++)
        {
            leftMax[i] = max(leftMax[i-1], nums[i-1]);
            rightMax[n-1-i] = max(rightMax[n-i], nums[n-i]);
        }
        long long ans = 0;
        for(int i=1; i<n-1; i++)
        {
            ans = max(ans, (long long)(leftMax[i]-nums[i])*rightMax[i]);
        }
        return ans;
    }
};