class Solution {
public:
    void sortColors(vector<int>& nums) {
        int color[3] = {0,};
        for (int i=0;i<nums.size();i++){
            color[nums[i]]++;
        }
        for (int i=0;i<color[0];i++){
            nums[i] = 0;
        }
        for (int i=0;i<color[1];i++){
            nums[i+color[0]] = 1;
        }
        for (int i=0;i<color[2];i++){
            nums[i+color[0]+color[1]] = 2;
        }

    }
};