class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // 초기 이동 검사
        if (grid[0][1] > 1 && grid[1][0] > 1) {
            return -1; // 첫 이동이 불가능한 경우
        }

        // 방문 시간 저장
        vector<vector<int>> minTime(m, vector<int>(n, INT_MAX));
        minTime[0][0] = 0;

        // 우선순위 큐: {현재 시간, 행, 열}
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        pq.emplace(0, 0, 0);

        // 방향 벡터: 상, 하, 좌, 우
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        while (!pq.empty()) {
            auto [currTime, x, y] = pq.top();
            pq.pop();

            // 최종 지점 도달
            if (x == m - 1 && y == n - 1) {
                return currTime;
            }

            // 이미 방문한 시간이 최소가 아니면 무시
            if (currTime > minTime[x][y]) {
                continue;
            }

            // 인접한 셀 탐색
            for (auto [dx, dy] : directions) {
                int nx = x + dx;
                int ny = y + dy;

                // 경계 체크
                if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
                    int waitTime = (grid[nx][ny] - currTime > 0 && (grid[nx][ny] - currTime) % 2 == 0)
                                       ? 1
                                       : 0;
                    int newTime = max(currTime + 1, grid[nx][ny]) + waitTime;

                    // 최소 시간 갱신
                    if (newTime < minTime[nx][ny]) {
                        minTime[nx][ny] = newTime;
                        pq.emplace(newTime, nx, ny);
                    }
                }
            }
        }

        return -1; // 도달 불가능한 경우
    }
};