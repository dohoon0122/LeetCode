class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        vector<int> freq(26, 0);
        for (char c : s) {
            freq[c - 'a']++;
        }

        priority_queue<pair<char, int>> pq;
        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0) {
                pq.push({'a' + i, freq[i]});
            }
        }

        string result;
        while (!pq.empty()) {
            auto [char1, count1] = pq.top(); 
            pq.pop();
            
            int use = min(count1, repeatLimit);
            result.append(use, char1);
            count1 -= use;

            if (count1 > 0) {
                if (pq.empty()) break; 
                
                auto [char2, count2] = pq.top(); 
                pq.pop();
                
                result += char2;
                count2--;

                if (count2 > 0) pq.push({char2, count2});
                pq.push({char1, count1});
            }
        }
        return result;
    }
};