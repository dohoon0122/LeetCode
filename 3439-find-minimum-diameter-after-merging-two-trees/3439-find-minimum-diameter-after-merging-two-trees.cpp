class Solution {
public:
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n1 = edges1.size() + 1;
        int n2 = edges2.size() + 1;

        // 그래프 생성
        vector<vector<int>> graph1(n1), graph2(n2);
        for (auto& edge : edges1) {
            graph1[edge[0]].push_back(edge[1]);
            graph1[edge[1]].push_back(edge[0]);
        }
        for (auto& edge : edges2) {
            graph2[edge[0]].push_back(edge[1]);
            graph2[edge[1]].push_back(edge[0]);
        }

        // 각 트리의 지름 계산
        int diameter1 = computeDiameter(graph1);
        int diameter2 = computeDiameter(graph2);


        // 최소 지름 계산
        int newDiameter = ceil(diameter1 / 2.0) + ceil(diameter2 / 2.0) + 1;
        return max({diameter1, diameter2, newDiameter});
    }

    // BFS로 트리의 가장 먼 노드와 거리 반환
    pair<int, int> bfs(int start, const vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> dist(n, -1);
        queue<int> q;
        q.push(start);
        dist[start] = 0;

        int farthestNode = start, maxDist = 0;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int neighbor : graph[node]) {
                if (dist[neighbor] == -1) {
                    dist[neighbor] = dist[node] + 1;
                    q.push(neighbor);
                    if (dist[neighbor] > maxDist) {
                        maxDist = dist[neighbor];
                        farthestNode = neighbor;
                    }
                }
            }
        }

        return {farthestNode, maxDist};
    }

    // 트리의 지름 계산
    int computeDiameter(const vector<vector<int>>& graph) {
        if (graph.empty()) return 0; // 빈 트리의 지름은 0
        pair<int, int> farthest = bfs(0, graph);
        pair<int, int> otherEnd = bfs(farthest.first, graph);
        return otherEnd.second;
    }
};