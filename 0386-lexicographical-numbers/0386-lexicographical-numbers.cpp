class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> result;
        for (int i = 1; i < 10; ++i) {
            dfs(i, n, result);
        }
        return result;
    }
    
    void dfs(int current, int n, vector<int>& result) {
        if (current > n) return; // 범위를 벗어나면 종료
        result.push_back(current); // 현재 숫자를 추가
        
        // 자식 노드를 탐색 (10배씩 증가하면서 자식 노드 탐색)
        for (int i = 0; i < 10; ++i) {
            int next = current * 10 + i;
            if (next > n) return; // 범위를 벗어나면 종료
            dfs(next, n, result);
        }
    }
};