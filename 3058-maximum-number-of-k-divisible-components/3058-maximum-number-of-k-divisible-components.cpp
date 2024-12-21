class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<vector<int>> tree(n);
        for(const auto& edge : edges){
            tree[edge[0]].push_back(edge[1]);
            tree[edge[1]].push_back(edge[0]);
        }

        vector<bool> visited(n, false);
        int components = 0;

        function<long long(int)> dfs = [&](int node) -> long long {
            visited[node] = true;
            long long subtreeSum = values[node];

            for(int neighbor : tree[node]){
                if(!visited[neighbor]) {
                    long long childSum = dfs(neighbor);
                    if(childSum % k == 0){
                        components++;
                    } 
                    else{
                        subtreeSum += childSum;
                    }
                }
            }

            return subtreeSum;
        };

        long long totalSum = dfs(0);
        // Check if the entire tree can form a component
        if(totalSum % k == 0){
            components++;
        }

        return components;
    }
};