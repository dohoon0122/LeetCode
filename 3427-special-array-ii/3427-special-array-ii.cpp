class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {

        vector<int> prefix(nums.size(), 0);
        for(int i=1; i<nums.size(); i++){
            if(nums[i]%2 == nums[i-1] % 2){
                prefix[i] = prefix[i-1] + 1;
            }
            else{
                prefix[i] = prefix[i-1];
            }
        }

        vector<bool> ans;
        for(auto v: queries){
            int start = v[0];
            int end = v[1];
            ans.push_back(prefix[start]==prefix[end]);
        }
        return ans;
    }
};