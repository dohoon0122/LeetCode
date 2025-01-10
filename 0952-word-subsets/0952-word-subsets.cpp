class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> maxFreq(26, 0); // 'a' to 'z' 빈도 수

        for (const string& word : words2) {
            vector<int> freq(26, 0);
            for(const char& c: word){
                freq[c-'a']++;
            }

            for (int i = 0; i < 26; ++i) {
                maxFreq[i] = max(maxFreq[i], freq[i]);
            }
        }

        vector<string> ans;

        for (const string& word : words1) {
            vector<int> freq(26, 0);
            for(const char& c: word){
                freq[c-'a']++;
            }
            
            bool isUniversal = true;
            for (int i = 0; i < 26; ++i) {
                if (freq[i] < maxFreq[i]) {
                    isUniversal = false;
                    break;
                }
            }
            if (isUniversal) {
                ans.push_back(word);
            }
        }

        return ans;
    }
};