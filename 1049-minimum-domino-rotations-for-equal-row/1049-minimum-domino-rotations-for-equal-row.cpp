class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n = tops.size();
        int ans = verify(tops[0], tops, bottoms, n);
        if(ans!=-1 || tops[0]==bottoms[0]) return ans;
        else return verify(bottoms[0], tops, bottoms, n);
    }

    int verify(int x, vector<int>& tops, vector<int>& bottoms, int n){
        int top_rotate = 0;
        int bottom_rotate = 0;

        for(int i=0; i<n; i++){
            if(tops[i]!=x && bottoms[i]!=x) return -1;
            else if(tops[i]!=x) top_rotate++;
            else if(bottoms[i]!=x) bottom_rotate++;
        }

        return min(top_rotate, bottom_rotate);
    }
};