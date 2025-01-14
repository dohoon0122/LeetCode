class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        unordered_set<int> seenA, seenB;
        int commonCount = 0;
        vector<int> C(A.size(), 0);  

        for (int i = 0; i < A.size(); ++i) {
            if (seenB.count(A[i])) {
                ++commonCount;  
            }
            seenA.insert(A[i]);

            if (seenA.count(B[i])) {
                ++commonCount;  
            }
            seenB.insert(B[i]);

            C[i] = commonCount;
        }

        return C;
    }
};