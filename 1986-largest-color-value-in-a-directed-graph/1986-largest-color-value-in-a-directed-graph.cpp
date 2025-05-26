class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        Solution::colors = colors;
        int n = colors.size();
        adj_list = vector<vector<int>>(n);
        for(auto& edge: edges){
            adj_list[edge[0]].push_back(edge[1]);
        }

        count = vector<vector<int>>(n, vector<int>(26));
        is_visited = vector<bool>(n, false);
        in_stack = vector<bool>(n, false);

        int ans = 0;
        for(int i = 0; i < n; i++){
            ans = max(ans, DFS(i));
        }

        if(ans == INT_MAX) return -1;
        return ans;
    }

    int DFS(int node){
        if(in_stack[node]) return INT_MAX;
        if(is_visited[node]) return count[node][colors[node] - 'a'];

        is_visited[node] = true;
        in_stack[node] = true;
        for(auto& v: adj_list[node]){
            if(DFS(v)==INT_MAX) return INT_MAX;
            for(int i=0; i<26; i++){
                count[node][i] = max(count[node][i], count[v][i]);
            }
        }

        count[node][colors[node] - 'a']++;
        in_stack[node] = false;
        return count[node][colors[node] - 'a'];
    }

    string colors;
    vector<vector<int>> adj_list;
    vector<vector<int>> count;
    vector<bool> is_visited;
    vector<bool> in_stack;
};