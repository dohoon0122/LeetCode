class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long totalSum = 0;
        int minAbsValue = INT_MAX;
        int negativeCount = 0;

        // 행렬 순회
        for (const auto& row : matrix) {
            for (int num : row) {
                totalSum += abs(num); // 절대값의 합
                if (num < 0) {
                    negativeCount++; // 음수 개수
                }
                minAbsValue = min(minAbsValue, abs(num)); // 최소 절대값
            }
        }

        // 음수의 개수가 홀수인 경우, 최소 절대값을 두 번 빼야 함
        if (negativeCount % 2 != 0) {
            totalSum -= 2 * minAbsValue;
        }

        return totalSum;
    }
};