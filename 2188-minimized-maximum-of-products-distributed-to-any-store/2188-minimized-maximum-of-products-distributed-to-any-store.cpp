class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int left = 1;
        int right = INT_MIN;
        for(int q: quantities){
            right = max(right, q);
        }

        int ans;
        while(left<right){
            int mid = left + (right-left)/2;
            if(isPossible(n, mid, quantities)){
                right = mid;
                ans = mid;
            }
            else{
                left = mid + 1;
            }
        }

        return left;
    }

    bool isPossible(int n, int x, vector<int>& quantities){
        int i = 0;
        for(int q: quantities){
            i += q/x;
            if(q%x) i++;
            if(i>n) return false;
        }
        return true;
    }
};