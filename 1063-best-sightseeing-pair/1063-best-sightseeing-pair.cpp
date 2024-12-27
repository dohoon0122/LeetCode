class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int N = values.size();
        vector<int> dp(N);

        dp[0] = values[0];

        int maxScore = 0;

        for (int i = 1; i < N; i++) {
            int curr = values[i] - i;
            maxScore = max(maxScore, dp[i - 1] + curr);

            int curr2 = values[i] + i;
            dp[i] = max(dp[i - 1], curr2);
        }

        return maxScore;


    }
};