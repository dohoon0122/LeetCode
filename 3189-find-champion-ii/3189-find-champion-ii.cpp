class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> indegree(n, 0);
        vector<vector<int>> graph(n);

        // 그래프 및 진입 차수 계산
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];
            graph[u].push_back(v);
            indegree[v]++;
        }

        // 진입 차수가 0인 노드 찾기
        int champion = -1;
        for (int i = 0; i < n; ++i) {
            if (indegree[i] == 0) {
                if (champion != -1) {
                    return -1; // 진입 차수가 0인 노드가 여러 개
                }
                champion = i;
            }
        }

        if (champion == -1) {
            return -1; // 진입 차수가 0인 노드가 없는 경우
        }

        return champion;
    }
};