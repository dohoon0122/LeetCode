class Solution {
public:
    vector<int> constructDistancedSequence(int n) {
        vector<int> ans(2 * n  -1, 0);
        vector<bool> is_visited(n+1, false);

        backtrack(0, ans, is_visited, n);

        return ans;
    }

    bool backtrack(int idx, vector<int>& ans, vector<bool>& is_visited, int n){
        if(idx == ans.size()){
            return true;
        }

        if(ans[idx]!= 0){
            return backtrack(idx+1, ans, is_visited, n);
        }

        for(int i = n; i>=1; i--){
            if(is_visited[i]) continue;

            is_visited[i] = true;
            ans[idx] = i;

            if(i == 1){
                if(backtrack(idx+1, ans, is_visited, n)) return true;
            }
            else if(idx+i < ans.size() && ans[idx+i] == 0){
                ans[idx+i] = i;
                if(backtrack(idx+1, ans, is_visited, n)) return true;
                ans[idx+i] = 0;
            }

            ans[idx] = 0;
            is_visited[i] = false;
        }
        
        return false;
    }
};
/*
0 1 2 3 4 5 6 7 8 9 
5 3 o o 3 5 o o o o

0 1 2 3 4 5 6 7 8 9 10 11
6 o o o o o 6 o o o  o  o
*/