class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int N = nums.size();
        vector<int> prefix_sum(N+1);
        for(int i=0; i<N; i++){
            prefix_sum[i+1] = prefix_sum[i] + nums[i];
        }

        // dp_l[i] = nums[i] 미포함, 왼쪽 k-len sub array sum 중 maximum 되는 start pos
        vector<int> dp_l(N, 0);
        int left_max = prefix_sum[k] - prefix_sum[0]; 
        for(int i = k + 1; i<N; i++){
            // l_val =  nums[i-k]~nums[i-1]
            int l_val = prefix_sum[i] - prefix_sum[i-k];
            if(l_val > left_max){
                left_max = l_val;
                dp_l[i] = i - k;
            }
            else{
                dp_l[i] = dp_l[i-1];
            }
        }

        // dp_r[i] = nums[i] 미포함, 오른쪽 k-len sub array sum 중 maximum 되는 start pos
        vector<int> dp_r(N, 0);
        int right_max = prefix_sum[N] - prefix_sum[N-k];

        for(int i = N-k-1; i>=0; i--){
            // r_val = nums[i+1] ~ nums[i+k]
            int r_val = prefix_sum[i+k+1] - prefix_sum[i+1];
            if(r_val >= right_max){
                right_max = r_val;
                dp_r[i] = i + 1;
            }
            else{
                dp_r[i] = dp_r[i+1];
            }
        }

        // mid
        int maxsum = 0;
        vector<int> ans;
        for(int i=k; i<N-2*k+1; i++){
            // mid_val = nums[i]~nums[i+k-1]
            int mid_val = prefix_sum[i+k] - prefix_sum[i];
            int left_idx = dp_l[i];
            int right_idx = dp_r[i+k-1];
            int left_val = prefix_sum[left_idx+k] - prefix_sum[left_idx];
            int right_val = prefix_sum[right_idx+k] - prefix_sum[right_idx];

            if(mid_val + left_val + right_val > maxsum){
                maxsum = mid_val + left_val + right_val;
                ans = {left_idx, i, right_idx};
            }
        }
        return ans;
    }
};