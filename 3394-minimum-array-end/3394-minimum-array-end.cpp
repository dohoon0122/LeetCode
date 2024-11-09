class Solution {
public:
    long long minEnd(int n, int x) {
        vector<int> on_bits;
        vector<int> off_bits;
        long long ll_x = (long long)x;
        for(int i=0; i<63; i++){
            if(ll_x & 1LL<<i) on_bits.push_back(i);
            else off_bits.push_back(i);
        }

        // basis
        long long ans = 0;
        for(int num: on_bits){
            ans|=(1<<num);
        }

        // last element
        int bit_change = off_bits.size();
        for(int i=0; i<bit_change; i++){
            if(1LL<<i & n-1){
                ans|=(1LL<<off_bits[i]);
            }
        }
        return ans;            
    }
};
/*
100
101
110
*/
