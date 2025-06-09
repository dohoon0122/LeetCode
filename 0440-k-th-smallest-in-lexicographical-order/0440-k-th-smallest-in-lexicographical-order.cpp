class Solution {
public:
    int findKthNumber(int n, int k) {
        int current = 1;  // 시작은 '1'부터
        k -= 1;  // 첫 번째 숫자는 이미 탐색된 상태로 시작하므로 k를 1 줄입니다.

        while (k > 0) {
            int steps = calculateSteps(n, current, current + 1);
            if (steps <= k) {
                // 다음 sibling 노드로 이동
                current += 1;
                k -= steps;
            } else {
                // 자식 노드로 내려감
                current *= 10;
                k -= 1;
            }
        }

        return current;
    }

    int calculateSteps(int n, long long first, long long last) {
        int steps = 0;
        while (first <= n) {
            steps += min(static_cast<long long>(n + 1), last) - first;
            first *= 10;
            last *= 10;
        }
        return steps;
    }
};