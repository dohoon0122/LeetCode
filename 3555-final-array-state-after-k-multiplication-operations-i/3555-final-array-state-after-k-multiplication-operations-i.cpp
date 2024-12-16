class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        int N = nums.size();
        for(int i=0; i<N; i++){
            pq.push({nums[i], i});
        }

        while(k--){
            auto [curr, idx] = pq.top();
            pq.pop();

            curr*=multiplier;
            nums[idx] = curr;
            pq.push({curr, idx});
        }

        return nums;
    }
};