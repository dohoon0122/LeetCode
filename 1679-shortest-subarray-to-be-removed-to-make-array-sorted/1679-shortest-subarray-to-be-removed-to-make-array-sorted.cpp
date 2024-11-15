class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size();

        // 왼쪽에서 증가하는 부분 탐색
        int left = 0;
        while (left + 1 < n && arr[left] <= arr[left + 1]) {
            left++;
        }
        // 이미 비내림차순인 경우
        if (left == n - 1) {
            return 0;
        }

        // 오른쪽에서 증가하는 부분 탐색
        int right = n - 1;
        while (right > 0 && arr[right - 1] <= arr[right]) {
            right--;
        }

        // 초기값: 전체 제거
        int minLength = min(n - left - 1, right);

        // 연결 가능한 가장 짧은 서브배열 제거
        int i = 0, j = right;
        while (i <= left && j < n) {
            if (arr[i] <= arr[j]) {
                minLength = min(minLength, j - i - 1);
                i++;
            } else {
                j++;
            }
        }

        return minLength;
    }
};