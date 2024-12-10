class Solution {
public:
    int maximumLength(string s) {
        int n = s.size();

        // 길이를 n에서 1까지 감소시키며 검사
        for (int length = n; length >= 1; --length) {
            unordered_map<string, int> freq;

            for (int i = 0; i <= n - length; ++i) {
                string substring = s.substr(i, length);
                
                // "special"한지 확인 (모두 같은 문자로 이루어졌는지)
                if (set<char>(substring.begin(), substring.end()).size() == 1) {
                    freq[substring]++;
                }
            }

            // 등장 횟수가 3 이상인 경우 길이 반환
            for (const auto& [key, count] : freq) {
                if (count >= 3) {
                    return length;
                }
            }
        }

        // 조건을 만족하는 서브스트링이 없는 경우
        return -1;
    }
};