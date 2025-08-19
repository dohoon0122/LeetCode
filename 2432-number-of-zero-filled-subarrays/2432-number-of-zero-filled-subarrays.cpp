class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        vector<long long> zero_cnt;
        int cnt = 0;
        for(auto& i: nums)
        {
            if(i==0)
            {
                cnt++;
            }
            else
            {
                if(cnt>0)
                {
                    zero_cnt.push_back(cnt);
                }
                cnt = 0;
            }
        }
        if(cnt>0) zero_cnt.push_back(cnt);

        long long ans = 0;
        for(auto& ll: zero_cnt)
        {
            ans += ll * (ll + 1) / 2;
        }
        return ans;
    }
};