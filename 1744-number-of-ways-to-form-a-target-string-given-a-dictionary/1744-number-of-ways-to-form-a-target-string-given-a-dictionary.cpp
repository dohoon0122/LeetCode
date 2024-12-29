class Solution {
public:
    int numWays(vector<string>& words, string target) {
        int N;
        N = words[0].size();

        vector<vector<int>> freq(N, vector<int>(26, 0));

        for(auto& word: words){
            for(int i=0; i<N; i++){
                freq[i][word[i]-'a']++;
            }        }


        int S = target.size();
        // dp[i][j] = words[*][i-1] 까지 봤을때 target[j-1] 까지 완성됨
        vector<vector<long long>> dp(N+1, vector<long long>(S+1, 0));
        // init
        // 0개 확인, 0 단어 완성
        dp[0][0] = 1;
        // words[i]까지 봤을때, 0단어 완성 가짓수
        for(int i=1; i<=N; i++){
            dp[i][0] = 1;
        }
        // 0개 확인했을때, i단어 완성 가짓수
        for(int i=1; i<=S; i++){
            dp[0][i] = 0;
        }



        // update
        const int MOD = 1e9 + 7;
        for(int i=1; i<=N; i++){
            for(int j=1; j<=S; j++){
                // i번째 단어 안쓴경우
                dp[i][j] = dp[i-1][j];
                // i번째 단어 쓴경우
                dp[i][j] += (dp[i-1][j-1] * freq[i-1][target[j-1]-'a']) % MOD;
                dp[i][j]%=MOD;

            }
        }
        
        return dp[N][S];
    }
};