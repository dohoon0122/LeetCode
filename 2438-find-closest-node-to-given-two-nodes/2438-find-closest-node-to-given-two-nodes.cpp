class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<int> dist1(n, INT_MAX);
        vector<int> dist2(n, INT_MAX);

        bfs(node1, edges, dist1);
        bfs(node2, edges, dist2);
        
        int ans = -1;
        int min_dist = INT_MAX;
        for(int i=0; i<n; i++){
            if(min_dist > max(dist1[i], dist2[i])){
                ans = i;
                min_dist= max(dist1[i], dist2[i]);
            }
        }
        
        return ans;
    }

    void bfs(int start, vector<int>& edges, vector<int>& dist){
        int n =edges.size();
        queue<int> q;
        q.push(start);
        dist[start] = 0;
        vector<bool> visited(n, false);
        visited[start] = true;

        while(!q.empty()){
            int curr = q.front();
            int next = edges[curr];
            q.pop();

            if(next==-1) break;
            if(!visited[next]){
                visited[next] = true;
                dist[next] = dist[curr] + 1;
                q.push(next);
            }
        }

        return;
    }
};