class Solution {
public:
    int maxDifference(string s) {
        vector<int> cnt(26, 0);
        int max_odd, max_even, min_odd, min_even;
        int n = s.size();
        for(char& c:s){
            cnt[c-'a']++;
        }
        min_even = n;
        min_odd = n;
        max_even = 0;
        max_odd = 0;
        for(int& i: cnt){
            if(i==0) continue;
            if(i%2==0){
                max_even = max(max_even, i);
                min_even = min(min_even, i);
            }
            else{
                max_odd = max(max_odd, i);
                min_odd = min(min_odd, i);
            }
        }
        return max_odd-min_even;
    }
};