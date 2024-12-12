class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> pq;
        long long ans = 0;
        for(auto gift: gifts){
            pq.push(gift);
            ans += gift;
        }

        for(int i=0; i<k; i++){
            int curr = pq.top();
            pq.pop();
            int remain = sqrt(curr);
            ans -= (curr - remain);
            pq.push(remain);
        }

        return ans;
    }
};