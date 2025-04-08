class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        vector<bool> NumCount(101, false);
        for(int i = n-1; i>=0; i--)
        {
            if(NumCount[nums[i]])
            {
                return i/3 + 1;
            }
            NumCount[nums[i]] = true;
        }
        return 0;
    }
};