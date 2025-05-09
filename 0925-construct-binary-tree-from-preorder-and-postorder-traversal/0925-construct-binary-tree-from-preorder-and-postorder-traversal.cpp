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
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int numOfNodes = preorder.size();

        vector<int> indexInPostorder(numOfNodes + 1);
        for (int index = 0; index < numOfNodes; index++) {
            indexInPostorder[postorder[index]] = index;
        }

        return constructTree(0, numOfNodes - 1, 0, preorder, indexInPostorder);
    }

    TreeNode* constructTree(int preStart, int preEnd, int postStart,
                            vector<int>& preorder,
                            vector<int>& indexInPostorder) {
        if (preStart > preEnd) return NULL;

        if (preStart == preEnd) {
            return new TreeNode(preorder[preStart]);
        }

        int leftRoot = preorder[preStart + 1];
        int numOfNodesInLeft = indexInPostorder[leftRoot] - postStart + 1;

        TreeNode* root = new TreeNode(preorder[preStart]);

        root->left = constructTree(preStart + 1, preStart + numOfNodesInLeft,
                                   postStart, preorder, indexInPostorder);

        root->right = constructTree(preStart + numOfNodesInLeft + 1, preEnd,
                                    postStart + numOfNodesInLeft, preorder,
                                    indexInPostorder);

        return root;
    }
};