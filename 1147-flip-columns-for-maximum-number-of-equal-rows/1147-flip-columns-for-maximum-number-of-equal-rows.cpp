class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<string, int> patternCount;
        int maxRows = 0;

        for (const auto& row : matrix) {
            string pattern;
            string invertedPattern;

            for (int cell : row) {
                // 기준 패턴: 첫 번째 값 기준으로 정규화
                pattern += (cell == row[0]) ? '0' : '1';
                invertedPattern += (cell == row[0]) ? '1' : '0';
            }

            // 패턴과 반전 패턴의 빈도 계산
            patternCount[pattern]++;
            maxRows = max(maxRows, patternCount[pattern]);
        }

        return maxRows;
    }
};
/*
0 0 0
0 0 1
1 1 0

*/
