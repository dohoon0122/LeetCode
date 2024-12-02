class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        stringstream ss(sentence);
        string substr;
        int n = searchWord.size();
        int idx = 0;
        while(ss>>substr){
            idx++;
            if(substr.size()<n) continue;
            bool wordFound = true;
            for(int i=0; i<n; i++){
                if(substr[i]!=searchWord[i]){
                    wordFound = false;
                    break;
                }
            }
            if(wordFound) return idx;            
        }
        return -1;
    }
};