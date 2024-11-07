class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int ans = 0;

        for(int i=0; i<24; i++){
            int temp = 0;
            for(int num: candidates){
                if(num & 1<<i) temp++;
            }
            ans = max(ans, temp);
        }


        return ans;
    }
};