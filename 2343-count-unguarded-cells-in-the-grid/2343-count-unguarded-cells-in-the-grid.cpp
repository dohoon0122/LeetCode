class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        unordered_set<int> guarded;
        unordered_set<int> obstacles; 

        for (auto& guard : guards) {
            obstacles.insert(guard[0] * n + guard[1]);
        }
        for (auto& wall : walls) {
            obstacles.insert(wall[0] * n + wall[1]);
        }

        vector<pair<int, int>> delta = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};


        for (auto& guard : guards) {
            for (auto& d : delta) {
                int x = guard[0];
                int y = guard[1];
                while (true) {
                    x += d.first;
                    y += d.second;
                    if (x < 0 || x >= m || y < 0 || y >= n || obstacles.count(x * n + y)) {
                        break;
                    }
                    guarded.insert(x * n + y);
                }
            }
        }
        return m * n - obstacles.size() - guarded.size();
    }
};