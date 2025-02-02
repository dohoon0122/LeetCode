class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        if (n<=1) return true;
        
        int temp = 0;
        for(int i=0; i<n-1; i++){
            if(nums[i]>nums[i+1]){
                temp++;
            }
        }
        if(nums[0]<nums[n-1]) temp++;

        return temp<=1;
    }
};