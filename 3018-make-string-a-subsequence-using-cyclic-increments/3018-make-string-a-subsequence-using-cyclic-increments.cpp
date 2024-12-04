class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int i = 0, j = 0; // 포인터 초기화

        while (i < str1.size() && j < str2.size()) {
            // 현재 문자가 같거나, str1[i]를 str2[j]로 변경 가능하면 진행
            if (str1[i] == str2[j] || (str1[i] - 'a' + 1) % 26 == str2[j] - 'a') {
                ++j; // str2의 다음 문자로 이동
            }
            ++i; // str1의 다음 문자로 이동
        }

        // str2의 모든 문자를 처리할 수 있으면 true
        return j == str2.size();
    }
};