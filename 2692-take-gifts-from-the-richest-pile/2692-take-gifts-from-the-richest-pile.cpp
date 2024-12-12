class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> pq;
        for(auto gift: gifts){
            pq.push(gift);
        }

        for(int i=0; i<k; i++){
            int curr = pq.top();
            pq.pop();
            int remain = (int)sqrt(curr);
            pq.push(remain);
        }

        long long ans = 0;
        while(!pq.empty()){
            int temp = pq.top();
            pq.pop();
            ans += temp;
        }

        return ans;
    }
};