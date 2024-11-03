class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size()!=goal.size()) return false;


        s += s;
        int n = s.size(), m = goal.size();
        vector<int> pi = getPartialMatch(goal);

        int begin = 0, matched = 0;

        while(begin<=n-m){
            if(matched < m && s[begin+matched] == goal[matched]){
                matched++;

                if(matched == m) return true;
            }
            else{
                if(matched == 0) begin++;
                else{
                    begin += matched - pi[matched - 1];
                    matched = pi[matched - 1];
                }
            }
        }

        return false;
    }

    vector<int> getPartialMatch(string& s){
        int m = s.size();
        vector<int> pi(m, 0);
        int begin = 1, matched = 0;

        while(begin+matched<m){
            if(s[begin+matched] == s[matched]){
                matched++;
                pi[begin+matched - 1] = matched;
            }
            else{
                if(matched == 0) begin++;
                else{
                    begin+=matched-pi[matched - 1];
                    matched = pi[matched - 1];
                }
            }
        }

        return pi;
    }
};