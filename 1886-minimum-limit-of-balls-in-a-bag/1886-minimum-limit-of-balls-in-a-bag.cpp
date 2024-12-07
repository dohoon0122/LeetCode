class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int n = nums.size();
        int bags = n + maxOperations;

        int left = 1, right = INT_MIN;
        for(int b: nums){
            right = max(right, b);
        }

        while(left<right){
            int mid = left + (right-left)/2;
            if(isPossible(nums, mid, bags)){
                right = mid;
            }
            else{
                left = mid + 1;
            }
        }

        return left;
    }

    bool isPossible(vector<int>& nums, int dist, int bags){
        int bag = 0;
        for(auto ball: nums){
            bag += ball/dist;
            if(ball%dist) bag++;
            if(bag>bags) return false;
        }
        return true;
    }
};