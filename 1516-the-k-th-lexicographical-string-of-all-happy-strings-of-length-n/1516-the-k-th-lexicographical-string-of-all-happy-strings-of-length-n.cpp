class Solution {
public:
    string getHappyString(int n, int k) {
        int max_k = 3 * (1<<(n-1));
        if(k>max_k) return "";

        string ans(n, 'a');
        unordered_map<char, char> dec = {{'a', 'b'}, {'b', 'a'}, {'c', 'a'}};
        unordered_map<char, char> inc = {{'a', 'c'}, {'b', 'c'}, {'c', 'b'}};

        int a_group = 1;
        int b_group = a_group + (1<<(n-1));
        int c_group = b_group + (1<<(n-1));

        if(k<b_group){
            ans[0] = 'a';
            k-=a_group;
        }
        else if(k<c_group){
            ans[0] = 'b';
            k-=b_group;
        }
        else{
            ans[0] = 'c';
            k-=c_group;
        }
        for(int i=1; i<n; i++){
            int mid = 1<<(n-i-1);
            if(k<mid){
                ans[i] = dec[ans[i-1]];
            }
            else{
                ans[i] = inc[ans[i-1]];
                k-=mid;
            }
        }

        return ans;
    }
};