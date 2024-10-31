class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
    vector<int> lis(n, 1), lds(n, 1);
    
    // LIS 계산 (왼쪽부터 오른쪽으로 증가하는 수열)
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (nums[j] < nums[i]) {
                lis[i] = max(lis[i], lis[j] + 1);
            }
        }
    }
    
    // LDS 계산 (오른쪽부터 왼쪽으로 감소하는 수열)
    for (int i = n - 1; i >= 0; --i) {
        for (int j = n - 1; j > i; --j) {
            if (nums[j] < nums[i]) {
                lds[i] = max(lds[i], lds[j] + 1);
            }
        }
    }

    // 최대 산 배열의 길이 계산
    int max_mountain_len = 0;
    for (int i = 1; i < n - 1; ++i) {
        if (lis[i] > 1 && lds[i] > 1) {
            max_mountain_len = max(max_mountain_len, lis[i] + lds[i] - 1);
        }
    }
    
    // 최소 제거 요소 수
    return n - max_mountain_len;
    }
};