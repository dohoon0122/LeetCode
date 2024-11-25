class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        // 목표 상태와 초기 상태
        string target = "123450";
        string start;
        for (auto& row : board) {
            for (int num : row) {
                start += to_string(num);
            }
        }

        // 이동 가능한 방향: 각 인덱스에서 이동 가능한 위치
        vector<vector<int>> neighbors = {
            {1, 3},        // index 0
            {0, 2, 4},     // index 1
            {1, 5},        // index 2
            {0, 4},        // index 3
            {1, 3, 5},     // index 4
            {2, 4}         // index 5
        };

        // BFS 초기화
        queue<pair<string, int>> q; // {현재 상태, 이동 횟수}
        unordered_set<string> visited; // 방문한 상태
        q.push({start, 0});
        visited.insert(start);

        while (!q.empty()) {
            auto [current, steps] = q.front();
            q.pop();

            // 목표 상태에 도달한 경우
            if (current == target) {
                return steps;
            }

            // 0의 위치를 찾고 이동 가능한 모든 상태 탐색
            int zeroPos = current.find('0');
            for (int neighbor : neighbors[zeroPos]) {
                string next = current;
                swap(next[zeroPos], next[neighbor]); // 0과 이웃 숫자 교환
                if (!visited.count(next)) {
                    q.push({next, steps + 1});
                    visited.insert(next);
                }
            }
        }

        return -1; // 해결 불가능한 경우
    }
};