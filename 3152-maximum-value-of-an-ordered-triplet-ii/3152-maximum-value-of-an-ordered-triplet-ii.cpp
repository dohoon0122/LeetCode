class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n= nums.size();
        vector<int> leftmax(n), rightmax(n);
        for(int i=1; i<n-1;i++)
        {
            leftmax[i] = max(leftmax[i-1], nums[i-1]);
            rightmax[n-1-i] = max(rightmax[n-i], nums[n-i]);
        }
        long long ans = 0;
        for(int i=1; i<n-1; i++)
        {
            ans = max(ans, (long long)(leftmax[i]-nums[i])*rightmax[i]);
        }
        return ans;
    }
};
// 0 n-2 n-1