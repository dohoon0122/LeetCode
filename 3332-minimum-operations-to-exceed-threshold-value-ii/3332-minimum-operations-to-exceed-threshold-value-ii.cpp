class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long, vector<long long>, greater<>> pq;
        for(int i=0; i<nums.size(); i++){
            pq.push(nums[i]);
        }

        int ans = 0;
        while(pq.size()>=2){
            long long a = pq.top();
            if(a>=k) break;
            pq.pop();
            long long b = pq.top();
            pq.pop();
            pq.push(min(a, b)*2 + max(a,b));
            ans++;
        }
        return ans;
    }
};