class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        vector<int> ans = nums;
        sort(nums.begin(), nums.end());

        unordered_map<int, int> val_group; // { val, groupIdx }
        val_group[nums[0]] = 0;

        unordered_map<int, queue<int>> group; // { groupIdx, group }
        group[0].push(nums[0]);

        int n = nums.size();
        int curr = 0;
        for(int i=1; i<n; i++){
            if(abs(nums[i] - nums[i-1]) > limit) curr++;

            val_group[nums[i]] = curr;
            group[curr].push(nums[i]);
        }

        for(int i=0; i<n; i++){
            int val = ans[i];
            int idx = val_group[val];
            ans[i] = group[idx].front();
            group[idx].pop();
        }

        return ans;
    }
};