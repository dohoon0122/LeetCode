class Solution {
public:
    bool canConstruct(string s, int k) {
        if(s.size()<k) return false;

        vector<bool> isEven(26, true);
        for(char& c: s){
            isEven[c-'a'] = !isEven[c-'a'];
        }

        int cntOdd = 0;
        for(bool b: isEven){
            if(!b) cntOdd++;
        }

        if(cntOdd>k) return false;
        return true;
    }
};