class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size();
        int n = heightMap[0].size();
        if (m < 3 || n < 3) return 0;

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> minHeap;
        vector<vector<bool>> visited(m, vector<bool>(n, false));


        for (int i = 0; i < m; ++i) {
            for (int j : {0, n - 1}) {
                minHeap.push({heightMap[i][j], {i, j}});
                visited[i][j] = true;
            }
        }
        for (int j = 0; j < n; ++j) {
            for (int i : {0, m - 1}) {
                minHeap.push({heightMap[i][j], {i, j}});
                visited[i][j] = true;
            }
        }


        int trappedWater = 0;
        int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int maxHeight = 0;

        while (!minHeap.empty()) {
            auto [h, pos] = minHeap.top();
            minHeap.pop();
            int x = pos.first, y = pos.second;

            maxHeight = max(maxHeight, h);

            for (auto& dir : directions) {
                int nx = x + dir[0], ny = y + dir[1];
                if (nx >= 0 && ny >= 0 && nx < m && ny < n && !visited[nx][ny]) {
                    visited[nx][ny] = true;

                    if (heightMap[nx][ny] < maxHeight) {
                        trappedWater += maxHeight - heightMap[nx][ny];
                    }

                    minHeap.push({heightMap[nx][ny], {nx, ny}});
                }
            }
        }

        return trappedWater;
    }
};