class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n, -1);
        vector<bool> visited(n, false);

        vector<vector<int>> adj_list(n, vector<int>());
        for(auto e: edges){
            adj_list[e[0]-1].push_back(e[1]-1);
            adj_list[e[1]-1].push_back(e[0]-1);
        }

        stack<int> s;
        s.push(0);
        int start_node = -1;
        while(!s.empty()){
            int curr = s.top();
            visited[curr] = true;
            s.pop();
            for(auto v: adj_list[curr]){
                if(!visited[v]){
                    parent[v] = curr;
                    s.push(v);
                }
                else if(v!=parent[curr] && start_node == -1){
                    start_node = v;
                    parent[v] = curr;
                }
            }
        }
        unordered_set<int> cycle_node;
        cycle_node.insert(start_node);
        int curr = parent[start_node];

        while(curr!=start_node){
            cycle_node.insert(curr);
            curr = parent[curr];
        }

        for(int i=n-1;i>=0;i--){
            if(cycle_node.count(edges[i][0]-1) && cycle_node.count(edges[i][1]-1)) return edges[i];
        }
        return {};
    }
};