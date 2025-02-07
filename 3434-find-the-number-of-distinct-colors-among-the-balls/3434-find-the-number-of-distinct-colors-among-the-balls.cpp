class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int, int> idx_color; // {idx, color}
        unordered_map<int, int> color_cnt; // {color, cnt}

        int n = queries.size();
        vector<int> ans(n);
        int prev = 0;
        for(int i=0; i<n; i++){
            int idx = queries[i][0];
            int color = queries[i][1];
            int curr = prev;

            if(color_cnt[color] == 0) curr++;
            color_cnt[color]++;

            int prev_color = idx_color[idx];
            idx_color[idx] = color;
            
            if(prev_color!=0) {
                color_cnt[prev_color]--;
                if(color_cnt[prev_color] == 0) curr--;
            }
            
            ans[i] = curr;
            prev = curr;
        }

        return ans;
    }
};