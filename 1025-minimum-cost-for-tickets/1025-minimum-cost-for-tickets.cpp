class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int N = days.size();
        // dp[date] = min cost of date
        
        int idx = 0;
        int last_date = days[N-1];
        vector<int>dp(last_date+1, 0);

        cout<<last_date;
        for(int i=1; i<=last_date; i++){
            if(i<days[idx]) dp[i] = dp[i-1];
            else{
                dp[i] = min({
                    dp[i-1>0?i-1:0] + costs[0],
                    dp[i-7>0?i-7:0] + costs[1],
                    dp[i-30>0?i-30:0] + costs[2]
                    });
                idx++;
            }
        }
        
        return dp[last_date];

    }
};