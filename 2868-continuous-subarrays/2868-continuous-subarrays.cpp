class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        int n = nums.size();
    long long total = 0;
    int left = 0;

    deque<int> maxDeque; // 최대값을 유지
    deque<int> minDeque; // 최소값을 유지

    for (int right = 0; right < n; ++right) {
        // 최대값 deque 업데이트
        while (!maxDeque.empty() && maxDeque.back() < nums[right])
            maxDeque.pop_back();
        maxDeque.push_back(nums[right]);

        // 최소값 deque 업데이트
        while (!minDeque.empty() && minDeque.back() > nums[right])
            minDeque.pop_back();
        minDeque.push_back(nums[right]);

        // 조건을 만족하지 않으면 left를 증가
        while (!maxDeque.empty() && !minDeque.empty() && maxDeque.front() - minDeque.front() > 2) {
            if (maxDeque.front() == nums[left]) maxDeque.pop_front();
            if (minDeque.front() == nums[left]) minDeque.pop_front();
            ++left;
        }

        // 조건을 만족하는 부분 배열의 개수 더하기
        total += (right - left + 1);
    }

    return total;
    }
};