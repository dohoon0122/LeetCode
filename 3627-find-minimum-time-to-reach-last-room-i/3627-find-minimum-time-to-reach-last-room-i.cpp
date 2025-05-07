class Solution {
public:
    vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size();
        int m = moveTime[0].size();
        vector<vector<bool>> bVisited(n, vector<bool>(m, false));

        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
        // time, row, col
        pq.push({0, 0, 0});
        bVisited[0][0] = true;
        while(!pq.empty())
        {
            int time = pq.top()[0];
            int row = pq.top()[1];
            int col = pq.top()[2];
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
                if(start_time > time)
                {
                    pq.push({start_time+1, n_row, n_col});
                }
                else
                {
                    pq.push({time+1, n_row, n_col});
                }
                bVisited[n_row][n_col] = true;
            }
        }

        return 0;
    }
};