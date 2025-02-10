class Solution {
public:
    string clearDigits(string s) {
        string st = "";
        for(int i=0; i<s.size(); i++){
            char c= s[i];
            if('0'<=c && c<= '9'){
                st.pop_back();
            }
            else{
                st+=c;
            }
        }
        return st;
    }
};