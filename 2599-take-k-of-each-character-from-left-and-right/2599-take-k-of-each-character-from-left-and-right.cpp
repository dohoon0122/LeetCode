class Solution {
public:
    int takeCharacters(string s, int k) {
        int n = s.length();
        unordered_map<char, int> count;

        // 전체 문자열에서 각 문자의 개수를 계산
        for (char c : s) {
            count[c]++;
        }

        // 필요한 문자의 총 개수가 부족한 경우 -1 반환
        if (count['a'] < k || count['b'] < k || count['c'] < k) {
            return -1;
        }

        // 슬라이딩 윈도우로 중간 부분에서 유지할 수 있는 최대 길이를 찾기
        int maxMiddleLength = 0;
        unordered_map<char, int> windowCount = {{'a', 0}, {'b', 0}, {'c', 0}};
        int left = 0;

        for (int right = 0; right < n; ++right) {
            windowCount[s[right]]++;

            // 중간 부분에서 각 문자의 개수가 총 개수 - k를 초과하지 않도록 유지
            while (windowCount['a'] > count['a'] - k ||
                   windowCount['b'] > count['b'] - k ||
                   windowCount['c'] > count['c'] - k) {
                windowCount[s[left]]--;
                left++;
            }

            // 현재 윈도우 길이 업데이트
            maxMiddleLength = max(maxMiddleLength, right - left + 1);
        }

        // 최소 이동 계산
        return n - maxMiddleLength;
    }
};