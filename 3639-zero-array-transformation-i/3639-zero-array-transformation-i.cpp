class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> temp(n+1, 0);
        for(const auto& q: queries){
            int left = q[0];
            int right = q[1];

            temp[left] += 1;
            temp[right+1] -= 1; 
        }

        vector<int> prefix_sum;
        int curr = 0;
        for(int d: temp){
            curr += d;
            prefix_sum.push_back(curr);
        }
        for(int i=0; i<n; i++){
            if(prefix_sum[i] < nums[i]) return false;
        }
        return true;
    }
};