class Solution {
public:
    bool primeSubOperation(vector<int>& nums) {
        int n = nums.size();
        vector<int> primes = getPrime(1000);
        int n_p = primes.size();

        int prev = 0;
        for(int i = 0; i < n; i++){
            bool i_check = false;
            // nums[i] 보다 작은 prime중 최대값 찾는 식(binary search)
            int left = 0;
            int right = n_p - 1;
            int p_idx = -1;

            while(left <= right){
                int mid = left + (right - left) / 2;
                if(primes[mid] < nums[i]){
                    p_idx = mid;
                    left = mid + 1;
                }
                else{
                    right = mid - 1;
                }
            }

            // p_idx 부터 nums[i] - prime[j]가 prev 보다 커지는 최소값 찾는 binary search
            left = 0;
            right = p_idx;
            int nmp = nums[i];
            
            while(left <= right){
                int mid = left + (right - left) / 2;
                if(nums[i] - primes[mid] > prev){
                    nmp = nums[i] - primes[mid];
                    left = mid + 1;
                }
                else{
                    right = mid - 1;
                }
            }
            nums[i] = nmp;

            if(nums[i] <= prev){
                return false;
            }
            prev = nums[i];
        }
        return true;
    }


    vector<int> getPrime(int limit){
        vector<bool> is_prime(limit + 1, true);
        is_prime[0] = is_prime[1] = false;
        for (int i = 2; i * i <= limit; i++) {
            if (is_prime[i]) {
                for (int j = i * i; j <= limit; j += i) {
                    is_prime[j] = false;
                }
            }
        }
        vector<int> primes;
        for (int i = 2; i <= limit; ++i) {
            if (is_prime[i]) {
                primes.push_back(i);
            }
        }
        return primes;
    }
};