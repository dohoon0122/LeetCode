class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<vector<pair<int, int>>> graph(n);
        for (int i = 0; i < n - 1; ++i) {
            graph[i].emplace_back(i + 1, 1); // 기본 도로
        }

        vector<int> result;

        for (auto& query : queries) {
            int u = query[0], v = query[1];
            graph[u].emplace_back(v, 1); // 새로운 도로 추가

            // 다익스트라 알고리즘으로 최단 경로 계산
            result.push_back(dijkstra(n, graph));
        }

        return result;
    }
    
    int dijkstra(int n, vector<vector<pair<int, int>>>& graph) {
        vector<int> dist(n, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

        dist[0] = 0;
        pq.emplace(0, 0); // {거리, 노드}

        while (!pq.empty()) {
            auto [currentDist, currentNode] = pq.top();
            pq.pop();

            // 더 긴 경로는 무시
            if (currentDist > dist[currentNode]) continue;

            // 인접 노드 확인
            for (auto& [neighbor, weight] : graph[currentNode]) {
                int newDist = currentDist + weight;
                if (newDist < dist[neighbor]) {
                    dist[neighbor] = newDist;
                    pq.emplace(newDist, neighbor);
                }
            }
        }

        return dist[n - 1];
    }
};