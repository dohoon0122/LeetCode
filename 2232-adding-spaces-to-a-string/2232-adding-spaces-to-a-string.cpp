class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string result;
        int j = 0; // spaces 배열의 포인터

        for (int i = 0; i < s.length(); i++) {
            // spaces[j]에 해당하는 인덱스에 도달하면 공백 삽입
            if (j < spaces.size() && i == spaces[j]) {
                result += ' ';
                j++;
            }
            result += s[i]; // 현재 문자 추가
        }

        return result;
    }
};