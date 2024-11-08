class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        vector<int> ans;
        int max_num = (1<<maximumBit) - 1;
        int temp = 0;
        for(int num: nums){
            temp^=num;
            ans.push_back(max_num - temp);
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};

