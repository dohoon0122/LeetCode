class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> ans(n);

        int left, right;
        int dl, dr;
        left = 0;
        right =0;
        dl = 0;
        dr = 0;

        for(int i=0; i<n; i++){
            ans[i] += dl;
            left += boxes[i] - '0';
            dl += left;

            int j = n-1 - i;
            ans[j] += dr;
            right += boxes[j] - '0';
            dr += right;
        }

        return ans;
    }
};