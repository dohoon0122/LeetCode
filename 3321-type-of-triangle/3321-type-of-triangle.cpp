class Solution {
public:
    string triangleType(vector<int>& nums) {
        int ans = 0;
        sort(nums.begin(), nums.end());
        if(nums[2] >= nums[0] + nums[1]) return "none";

        if(nums[0] == nums[1])
        {
            if(nums[1] == nums[2]) return "equilateral";
            else return "isosceles";
        }
        if(nums[1] == nums[2]) return "isosceles";
        else return "scalene";
    }
};