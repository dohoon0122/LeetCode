class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int, bool> is_even;

        for(auto& num: nums){
            if(!is_even.count(num)){
                is_even[num] = false;
            }
            else{
                is_even[num] = !is_even[num];
            }
        }
        for(auto& [num, cnt]: is_even){
            if(!cnt) return false;
        }
        return true;
    }
};