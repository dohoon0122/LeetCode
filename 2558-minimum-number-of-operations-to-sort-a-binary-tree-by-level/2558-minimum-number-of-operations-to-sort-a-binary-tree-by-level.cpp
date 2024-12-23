/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int minimumOperations(TreeNode* root) {
        if (!root) return 0;

        // 레벨별 노드 값을 저장
        vector<vector<int>> levels;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            vector<int> level;

            for (int i = 0; i < size; ++i) {
                TreeNode* node = q.front();
                q.pop();
                level.push_back(node->val);

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            levels.push_back(level);
        }

        // 각 레벨별 최소 스왑 계산
        int totalSwaps = 0;
        for (auto& level : levels) {
            totalSwaps += minSwapsToSort(level);
        }

        return totalSwaps;
    }

    int minSwapsToSort(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> sortedNums;
        for (int i = 0; i < n; ++i) {
            sortedNums.push_back({nums[i], i});
        }

        // 값 기준으로 정렬
        sort(sortedNums.begin(), sortedNums.end());

        // 사이클 디컴포지션을 통해 최소 스왑 계산
        vector<bool> visited(n, false);
        int swaps = 0;

        for (int i = 0; i < n; ++i) {
            if (visited[i] || sortedNums[i].second == i) {
                continue;
            }

            int cycleSize = 0;
            int j = i;

            while (!visited[j]) {
                visited[j] = true;
                j = sortedNums[j].second;
                ++cycleSize;
            }

            if (cycleSize > 1) {
                swaps += cycleSize - 1;
            }
        }

        return swaps;
    }
};