class Solution {
public:
    string robotWithString(string s) {
        vector<int> cnt(26, 0);
        for(char& c: s){
            cnt[c - 'a']++;
        }

        stack<char> st;
        string ans;
        char min_char = 'a';
        for(char& c: s){
            st.push(c);
            cnt[c - 'a']--;
            while(min_char != 'z' && cnt[min_char - 'a'] == 0){
                min_char++;
            }
            while(!st.empty() && st.top() <= min_char){
                ans.push_back(st.top());
                st.pop();
            }
        }

        return ans;
    }
};