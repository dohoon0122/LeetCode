class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        unordered_map<int,int> domino_cnt;
        for(int i=0; i<dominoes.size(); i++){
            int small = dominoes[i][0];
            int big = dominoes[i][1];
            if(small > big){
                int temp = small;
                small = big;
                big = temp;
            }
            int key = small*10+big;
            domino_cnt[key]++;
        }
        int ans = 0;
        for(auto& [key, val]: domino_cnt){
            if(val<2) continue;
            ans += (val * (val-1))/2;
        }
        return ans;
    }
};