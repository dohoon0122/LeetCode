class Solution {
public:
    vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size();
        int m = moveTime[0].size();
        vector<vector<bool>> bVisited(n, vector<bool>(m, false));

        priority_queue<tuple<int, int, int, bool>, vector<tuple<int, int, int, bool>>, greater<>> pq;
        // time, row, col, bIsOne
        pq.push({0, 0, 0, true});
        bVisited[0][0] = true;
        while(!pq.empty())
        {
            auto [time, row, col, bIsOne] = pq.top();
            pq.pop();

            if(row==n-1 && col==m-1) return time;

            for(auto& [d_row, d_col]: dir)
            {
                int n_row = row + d_row;
                int n_col = col + d_col;

                if(n_row < 0 || n_row >= n) continue;
                if(n_col < 0 || n_col >= m) continue;
                if(bVisited[n_row][n_col]) continue;

                int start_time = moveTime[n_row][n_col];
                int moving_time = 0;
                if(bIsOne) moving_time = 1;
                else moving_time = 2;

                if(start_time > time)
                {
                    pq.push({start_time + moving_time, n_row, n_col, !bIsOne});
                }
                else
                {
                    pq.push({time + moving_time, n_row, n_col, !bIsOne});
                }
                bVisited[n_row][n_col] = true;
            }
        }

        return 0;
    }
};