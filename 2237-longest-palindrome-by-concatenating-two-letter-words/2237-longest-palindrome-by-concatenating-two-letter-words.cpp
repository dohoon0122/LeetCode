class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> cnt;
        for(const auto& word: words){
            cnt[word]++;
        }
        int ans = 0;
        bool central = false;
        for(const auto& [word, WordCount]: cnt){
            if(word[0]==word[1]){
                if(WordCount %2 == 0){
                    ans+=WordCount;
                }
                else{
                    ans+=WordCount-1;
                    central = true;
                }
            }
            else if(word[0]<word[1] && cnt.count({word[1], word[0]})){
                ans+= 2* min(WordCount, cnt[{word[1], word[0]}]);
            }
        }
        if(central) ans++;

        return ans*2;
    }
};