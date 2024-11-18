class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        vector<int> prefix_sum = {0};
        int p = 0;
        for(int num: code){
            p+=num;
            prefix_sum.push_back(p);
        }

        int n = code.size();
        vector<int> ans;
        for(int i=0; i < n; i++){
            if(k > 0){
                int left = i + 1;
                int right = i + k;

                int temp = 0;
                if(left < n) temp -= prefix_sum[left];
                else temp -= prefix_sum[n];
                if(right < n) temp += prefix_sum[right + 1];
                else temp += (prefix_sum[right - n + 1] + prefix_sum[n]);

                ans.push_back(temp);
            }
            else if(k < 0){
                int left = i + k;
                int right = i - 1;

                int temp = 0;
                if(left < 0) temp += (prefix_sum[n] - prefix_sum[left + n]);
                else temp -= prefix_sum[left];
                if(right < 0) temp += prefix_sum[0];
                else temp += prefix_sum[right + 1];

                ans.push_back(temp);
            }
            else{
                ans.push_back(0);
            }
        }

        return ans;
    }
};

/*
0 1 2
3 4 2

0 1 2 3
0 3 7 9

0~1: p[2] - p[0]
1~2: p[3] - p[1]
0~2: p[3] - p[0]
*/