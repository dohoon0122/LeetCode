class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int, deque<int>> graph; // 인접 리스트
        unordered_map<int, int> inDegree, outDegree; // 진입 차수와 진출 차수

        // 그래프 생성 및 차수 계산
        for (auto& pair : pairs) {
            int u = pair[0], v = pair[1];
            graph[u].push_back(v);
            outDegree[u]++;
            inDegree[v]++;
        }

        // 시작 노드 찾기
        int startNode = pairs[0][0]; // 기본값
        for (auto& [node, out] : outDegree) {
            if (out > inDegree[node]) {
                startNode = node;
                break;
            }
        }

        // 오일러 경로를 위한 스택
        stack<int> stk;
        vector<int> result;
        stk.push(startNode);

        // DFS 기반 오일러 경로 생성
        while (!stk.empty()) {
            int node = stk.top();
            if (!graph[node].empty()) {
                int nextNode = graph[node].front();
                graph[node].pop_front();
                stk.push(nextNode);
            } else {
                result.push_back(node);
                stk.pop();
            }
        }

        // 결과를 역순으로 변환
        reverse(result.begin(), result.end());
        vector<vector<int>> arrangement;
        for (int i = 0; i < result.size() - 1; ++i) {
            arrangement.push_back({result[i], result[i + 1]});
        }

        return arrangement;
    }
};