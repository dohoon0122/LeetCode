class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int curr = num2;
        int bits_cnt = 0;
        while(curr){
            bits_cnt += (curr%2);
            curr/=2;
        }
        int max_bit = -1;
        curr = num1;
        while(curr){
            curr/=2;
            max_bit++;
        }

        max_bit = max(max_bit, bits_cnt-1);
        int ones = bits_cnt;
        int zeros = max_bit - bits_cnt + 1;

        //cout<<ones<<" "<<zeros<<endl;

        int ans = 0;
        for(int i=max_bit; i>=0; i--){
            if(1<<i & num1){
                if(ones){
                    ones--;
                    ans += (1<<i);
                }
                else{
                    zeros--;
                }
            }
            else{
                if(zeros){
                    zeros--;
                }
                else{
                    ans += (1<<i);
                    ones--;
                }
            }
            //cout<<ans<<endl;
        }
        return ans;
    }
};