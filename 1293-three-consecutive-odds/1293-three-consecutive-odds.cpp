class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int verify = 0;
        for (int num: arr){
            if(num%2){
                verify++;
                if (verify >= 3) return true;
            }
            else{
                verify = 0;
            }
        }
        return false;
    }
};