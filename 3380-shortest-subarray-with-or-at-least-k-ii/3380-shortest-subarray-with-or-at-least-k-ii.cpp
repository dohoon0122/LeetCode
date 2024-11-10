class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int minLength = INT_MAX;
        int windowStart = 0;
        int windowEnd = 0;
        vector<int> bitCounts(32, 0);  // 비트 카운트 배열

        while (windowEnd < nums.size()) {
            // 현재 숫자를 윈도우에 추가
            updateBitCounts(bitCounts, nums[windowEnd], 1);

            // OR 값이 조건을 만족하면 최소 길이 업데이트 및 윈도우 축소
            while (windowStart <= windowEnd &&
                   convertBitCountsToNumber(bitCounts) >= k) {
                minLength = min(minLength, windowEnd - windowStart + 1);

                // 윈도우 시작 위치의 숫자를 제거하고 윈도우 축소
                updateBitCounts(bitCounts, nums[windowStart], -1);
                windowStart++;
            }

            windowEnd++;
        }

        return minLength == INT_MAX ? -1 : minLength;
    }

    void updateBitCounts(vector<int>& bitCounts, int num, int delta) {
        for (int i = 0; i < 32; i++) {
            if (num & (1 << i)) {
                bitCounts[i] += delta;
            }
        }
    }

    int convertBitCountsToNumber(const vector<int>& bitCounts) {
        int orResult = 0;
        for (int i = 0; i < 32; i++) {
            if (bitCounts[i] > 0) {  // 해당 비트 위치에 1이 하나 이상 있으면
                orResult |= (1 << i);
            }
        }
        return orResult;
    }
};
