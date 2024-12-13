class Solution {
public:
    long long findScore(vector<int>& nums) {
        int N = nums.size();
        vector<bool> marked(N, false);

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq; // val, idx
        for(int i=0; i<N; i++){
            pq.push({nums[i], i});
        }

        long long ans = 0;
        while(!pq.empty()){
            auto [val, idx] = pq.top();
            pq.pop();
            if(marked[idx]) continue;
            else{
                ans += val;
                for(int i=-1; i<=1; i++){
                    int n_idx = idx + i;
                    if(0<=n_idx && n_idx<N){
                        marked[n_idx] = true;
                    }
                }
            }
        }

        return ans;
    }
};