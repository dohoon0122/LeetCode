class Solution {
public:
    int minimumLength(string s) {
        vector<int> cnt(26, 0);
        for(char& c: s){
            cnt[c-'a']++;
        }
        int ans = 0;
        for(int i=0; i<26; i++){
            int temp = cnt[i];
            if(temp%2){
                ans+=1;
            }
            else if(temp){
                ans+=2;
            }
        }
        return ans;
    }
};