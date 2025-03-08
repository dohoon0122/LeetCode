class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int left = 0;
        int white = 0;
        int ans = k;
        for(int i=0; i<blocks.size(); i++){
            if(blocks[i]=='W') white++;
            if(i-left+1 == k){
                ans = min(ans, white);
                if(blocks[left] == 'W') white--;
                left++;
            }
        }

        return ans;
    }
};