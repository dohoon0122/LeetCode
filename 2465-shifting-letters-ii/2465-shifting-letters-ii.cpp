class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> fbsum(n+1, 0);
        for(vector<int>& shift: shifts){
            if(shift[2] == 0){
                cout<<shift[0];
                fbsum[shift[0]]--;
                fbsum[shift[1]+1]++;
            }
            else{
                fbsum[shift[0]]++;
                fbsum[shift[1]+1]--;
            }
        }
        vector<int> prefix_sum(n);
        prefix_sum[0] = fbsum[0];
        for(int i=1; i<n; i++){
            prefix_sum[i] = fbsum[i];
            prefix_sum[i] += prefix_sum[i-1];
        }


        string ans = "";
        cout<<"Debugging"<<endl;
        for(int i=0; i<n; i++){
            int c = s[i] - 'a';
            c += prefix_sum[i];
            c %= 26;
            if(c<0) c+=26;
            ans += (c + 'a');
        }
        return ans;
    }
};

