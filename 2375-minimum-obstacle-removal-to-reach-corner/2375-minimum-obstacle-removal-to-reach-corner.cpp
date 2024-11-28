class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // 방향 벡터: 상, 하, 좌, 우
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        vector<vector<int>> dist(m, vector<int>(n, 1e9)); // 최단 거리 배열
        deque<pair<int, int>> dq; // 0-1 BFS를 위한 덱

        // 시작 지점 초기화
        dq.push_front({0, 0});
        dist[0][0] = 0;

        while (!dq.empty()) {
            auto [x, y] = dq.front();
            dq.pop_front();

            // 인접한 셀 탐색
            for (auto [dx, dy] : directions) {
                int nx = x + dx;
                int ny = y + dy;

                // 경계 검사
                if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
                    int newDist = dist[x][y] + grid[nx][ny];
                    if (newDist < dist[nx][ny]) {
                        dist[nx][ny] = newDist;
                        if (grid[nx][ny] == 0) {
                            dq.push_front({nx, ny}); // 비용이 0이면 앞에 삽입
                        } else {
                            dq.push_back({nx, ny}); // 비용이 1이면 뒤에 삽입
                        }
                    }
                }
            }
        }

        // 최종 지점까지의 최소 장애물 제거 횟수 반환
        return dist[m - 1][n - 1];
    }
};