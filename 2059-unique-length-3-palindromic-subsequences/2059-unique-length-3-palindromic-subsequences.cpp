class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<int> bidx(26, -1);
        vector<int> eidx(26, -1);
        for(int i=0; i<s.size(); i++){
            int curr = s[i] - 'a';
            if(bidx[curr] == -1){
                bidx[curr] = i;
            }

            eidx[curr] = i;
        }

        int ans = 0;
        for(int i=0;i<26;i++){
            if(bidx[i] == -1) continue;

            unordered_set<char> mid;
            for(int j=bidx[i]+1; j<eidx[i]; j++){
                mid.insert(s[j]);
            }

            ans += mid.size();
        }

        return ans;
    }
};