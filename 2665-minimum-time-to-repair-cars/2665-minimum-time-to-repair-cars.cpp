class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        long long left = 1;
        long long right = 1LL * cars * cars * 100;

        while(left<right){
            long long mid = left + (right-left)/2;
            long long repaired = 0;

            for(auto& rank: ranks){
                repaired += sqrt(1.0*mid/rank);
            }
            if(repaired<cars){
                left = mid + 1;
            }
            else{
                right = mid;
            }
        }

        return left;
    }
};