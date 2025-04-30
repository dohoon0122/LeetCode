class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int ans = 0;
        for(auto& number: nums)
        {
            string s = to_string(number);
            if(s.size()%2==0) ans++;
        }
        return ans;
    }
};