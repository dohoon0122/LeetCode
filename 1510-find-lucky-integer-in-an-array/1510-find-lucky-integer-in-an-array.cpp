class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int, int> freq;
        for(auto& i: arr){
            freq[i]++;
        }
        int ans = -1;
        for(auto& [key, val]: freq){
            if(key==val){
                ans = max(ans, key);
            }
        }
        return ans;
    }
};