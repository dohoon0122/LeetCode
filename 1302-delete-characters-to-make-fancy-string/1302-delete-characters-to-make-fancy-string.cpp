class Solution {
public:
    string makeFancyString(string s) {
        string ans = "";
        int cnt = 0;
        char prev = '\0';
        for(char&c: s){
            if(c == prev){
                cnt++;
            }
            else {
                cnt = 1;
                prev = c;
            }

            if(cnt<=2){
                ans+=c;
            }
        }

        return ans;
    }
};