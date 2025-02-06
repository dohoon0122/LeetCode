class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int, int> MulCnt;
        for(int i=0; i<n; ++i){
            for(int j=i+1; j<n; ++j){
                MulCnt[nums[i]*nums[j]]++;
            }
        }

        int ans = 0;
        for(auto [mul, cnt]: MulCnt){
            int EqualPair = cnt * (cnt - 1) / 2;
            ans += (8 * EqualPair);
        }

        return ans;
    }
};