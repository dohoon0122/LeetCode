class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        sort(candidates.begin(), candidates.end());
        int maximum = candidates.back();

        int n = 0; // n = max bit
        while(maximum){
            maximum/=2;
            n++;
        }
        
        vector<int> bit_count(n+1, 0);

        for(int num: candidates){
            int bit = 0;
            while(num){
                if(num%2) bit_count[bit]++;
                num/=2;
                bit++;
            }
        }

        int ans = 0;
        for(int c: bit_count){
            ans = max(ans, c);
        }

        return ans;
    }
};