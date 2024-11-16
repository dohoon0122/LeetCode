class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> result;

        for (int i = 0; i < n - k + 1; ++i) {
            vector<int> subarray(nums.begin() + i, nums.begin() + i + k);
            vector<int> sortedSubarray = subarray;

            // 정렬된 부분 배열 확인
            sort(sortedSubarray.begin(), sortedSubarray.end());
            bool isSorted = true, isConsecutive = true;

            for (int j = 1; j < k; ++j) {
                if (sortedSubarray[j] != sortedSubarray[j - 1] + 1) {
                    isConsecutive = false;
                }
                if (subarray[j] < subarray[j - 1]) {
                    isSorted = false;
                }
            }

            if (isSorted && isConsecutive) {
                result.push_back(sortedSubarray.back()); // 최대값 추가
            } else {
                result.push_back(-1); // 조건 불만족
            }
        }

        return result;
    }
};