class Solution {
public:
    int numTilePossibilities(string tiles) {
        unordered_set<string> ans;

        sort(tiles.begin(), tiles.end());

        return solve(tiles, "", 0, ans) - 1;
    }

private:
    int factorial(int n){
        if(n<=1) return 1;

        int result = 1;
        for(int i=2; i<=n; i++){
            result*=i;
        }
        return result;
    }

    int permutation(string& seq){
        vector<int> char_cnt(26, 0);
        for(char c: seq){
            char_cnt[c-'A']++;
        }
        int total = factorial(seq.length());
        for(int cnt: char_cnt){
            if(cnt>1){
                total /= factorial(cnt);
            }
        }
        return total;
    }

    int solve(string& tiles, string curr, int pos, unordered_set<string>& ans){
        if(pos>=tiles.length()){
            if(ans.insert(curr).second){
                return permutation(curr);
            }
            return 0;
        }

        return solve(tiles, curr, pos+1, ans) + solve(tiles, curr+tiles[pos], pos+1, ans);
    }
};