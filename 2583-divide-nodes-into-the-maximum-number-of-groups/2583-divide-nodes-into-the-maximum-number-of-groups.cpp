class Solution {
public:
    int magnificentSets(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n + 1);
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        vector<int> color(n + 1, 0);  // 0: 미방문, 1: 빨강, -1: 파랑
        vector<int> visited(n + 1, 0);
        int maxGroups = 0;

        for (int i = 1; i <= n; ++i) {
            if (visited[i]) continue;
            vector<int> component;
            queue<int> q;
            q.push(i);
            visited[i] = 1;
            component.push_back(i);

            while (!q.empty()) {
                int node = q.front();
                q.pop();
                for (int neighbor : graph[node]) {
                    if (!visited[neighbor]) {
                        visited[neighbor] = 1;
                        q.push(neighbor);
                        component.push_back(neighbor);
                    }
                }
            }

            int maxDepth = 0;
            for (int start : component) {
                int depth = bfsMaxDepth(graph, start, n);
                if (depth == -1) return -1; // 홀수 길이 사이클이 있으면 불가능
                maxDepth = max(maxDepth, depth);
            }
            maxGroups += maxDepth;
        }
        return maxGroups;
    }

    int bfsMaxDepth(vector<vector<int>>& graph, int start, int n) {
        queue<int> q;
        vector<int> dist(n + 1, -1);
        q.push(start);
        dist[start] = 0;
        int maxDepth = 0;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            maxDepth = max(maxDepth, dist[node]);
            for (int neighbor : graph[node]) {
                if (dist[neighbor] == -1) {
                    dist[neighbor] = dist[node] + 1;
                    q.push(neighbor);
                } else if ((dist[neighbor] % 2) == (dist[node] % 2)) {
                    return -1; // 홀수 길이 사이클 발견
                }
            }
        }
        return maxDepth + 1; // 1부터 시작하는 그룹이므로 1 더함
    }
};