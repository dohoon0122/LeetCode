class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());

        vector<int> facPos;
        for(auto& f: factory){
            for(int i=0;i<f[1];i++){
                facPos.push_back(f[0]);
            }
        }

        int n = robot.size();
        int m = facPos.size();

        vector<vector<long long>> dp(n+1, vector<long long>(m+1, 1e12));
        dp[0][0] = 0;



        for(int i=0; i<=n; i++){
            for(int j=i; j<=m; j++){
                if(i>0 && dp[i-1][j-1] != 1e12){
                    dp[i][j] = min(dp[i][j], dp[i-1][j-1] + abs(robot[i-1] - facPos[j-1]));
                }
                if(j>0 && dp[i][j-1] != 1e12){
                    dp[i][j] = min(dp[i][j], dp[i][j-1]);
                }
            }
        }

        return dp[n][m];
    }
};