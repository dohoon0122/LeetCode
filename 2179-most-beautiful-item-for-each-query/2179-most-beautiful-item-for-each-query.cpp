class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort(items.begin(), items.end());

        // 가격별 최대 아름다움 업데이트
        map<int, int> priceToMaxBeauty;
        int maxBeauty = 0;
        for (const auto& item : items) {
            maxBeauty = max(maxBeauty, item[1]);
            priceToMaxBeauty[item[0]] = maxBeauty;
        }

        // 쿼리를 처리하면서 각 가격에 대한 최대 아름다움 찾기
        vector<int> result;
        for (int q : queries) {
            // 이진 탐색으로 현재 쿼리 가격 이하의 최대 아름다움 찾기
            auto it = priceToMaxBeauty.upper_bound(q);
            if (it == priceToMaxBeauty.begin()) {
                result.push_back(0); // 가격 이하 아이템이 없는 경우
            } else {
                result.push_back(prev(it)->second); // 가장 가까운 가격의 최대 아름다움
            }
        }

        return result;
    }
};