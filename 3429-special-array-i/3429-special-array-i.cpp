class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return true;
        bool is_odd = nums[0]%2;
        for(int i=1; i<n; i++){
            if (is_odd==nums[i]%2) return false;
            is_odd = nums[i]%2;
        }
        return true;
    }
};