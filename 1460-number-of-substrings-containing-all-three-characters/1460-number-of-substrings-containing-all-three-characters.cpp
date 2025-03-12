class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        vector<int> cnt(3, 0);
        
        int ans = 0;
        int left = 0, right = 0;
        while(right<n){
            char curr = s[right];
            cnt[curr-'a']++;
            while(complete(cnt)){
                ans += (n - right);
                char left_c = s[left];
                cnt[left_c-'a']--;
                left++;
            }
            right++;
        }

        return ans;
    }

    bool complete(vector<int>& cnt) {
        return cnt[0] > 0 && cnt[1] > 0 && cnt[2] > 0;
    }
};