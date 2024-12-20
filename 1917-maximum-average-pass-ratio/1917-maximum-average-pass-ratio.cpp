class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int N = classes.size();

        auto comp = [](const pair<int, int>& a, const pair<int, int>& b){
            double incA = (double)(a.first + 1) / (a.second + 1) - (double)a.first / a.second;
            double incB = (double)(b.first + 1) / (b.second + 1) - (double)b.first / b.second;

            return incA < incB;
        };

        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> pq(comp);

        double ans = 0;
        for(const auto& cls: classes){
            pq.push({cls[0], cls[1]});
            ans += (double)cls[0]/cls[1];
        }

        while(extraStudents--){
            auto [pass, total] = pq.top();
            pq.pop();
            ans -= (double)pass/total;

            pq.push({pass+1, total+1});
            ans += (double)(pass+1)/(total+1);
        }

        return ans/N;
    }
};