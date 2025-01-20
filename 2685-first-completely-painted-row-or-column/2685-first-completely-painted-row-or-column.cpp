class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<int> rowCount(m), colCount(n);
        unordered_map<int, pair<int, int>> pos;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                int temp = mat[i][j];
                pos[temp] = {i, j};
            }
        }

        for (int i = 0; i < arr.size(); i++) {
            auto [row, col] = pos[arr[i]];

            rowCount[row]++;
            colCount[col]++;

            if (rowCount[row] == n || colCount[col] == m) {
                return i;
            }
        }

        return -1;
    }
};