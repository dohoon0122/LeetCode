class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> prefixSum(n + 1, 0);

        // 누적합 계산
        for (int i = 0; i < n; ++i) {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }

        // 최소 힙 (deque로 구현)
        deque<int> dq;
        int minLength = INT_MAX;

        for (int i = 0; i <= n; ++i) {
            // 현재 구간의 합이 k 이상이 되도록 유지
            while (!dq.empty() && prefixSum[i] - prefixSum[dq.front()] >= k) {
                minLength = min(minLength, i - dq.front());
                dq.pop_front();
            }

            // 힙 내의 누적합이 현재보다 크거나 같은 경우 제거
            while (!dq.empty() && prefixSum[i] <= prefixSum[dq.back()]) {
                dq.pop_back();
            }

            // 현재 인덱스 추가
            dq.push_back(i);
        }

        return minLength == INT_MAX ? -1 : minLength;
    }
};