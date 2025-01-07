class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string> ans;
        for(const string& word: words){
            for(const string& otherWord: words){
                if(word != otherWord && otherWord.find(word) != string::npos){
                    ans.push_back(word);
                    break;
                }
            }
        }
        return ans;
    }
};