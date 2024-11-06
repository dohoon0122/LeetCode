class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        int n = nums.size();
        int bits = -1;

        int p_max = 0;
        int c_min = 1<<8, c_max = 0;

        for(int i=0; i<n; i++){
            int curr_bit = countSetBits(nums[i]);

            if(curr_bit==bits){
                if(nums[i]<c_min) c_min = nums[i];
                if(nums[i]>c_max) c_max = nums[i];
            }
            else{
                if(c_min<p_max) return false;

                bits = curr_bit;
                p_max = c_max;
                c_min = nums[i];
                c_max = nums[i];
            }
        }
        if(c_min<p_max) return false;

        return true;
    }

    int countSetBits(int n) {
        int count = 0;
        while (n > 0) {
            count += n & 1;
            n >>= 1;
        }
        return count;
    }
};