class Solution {
public:
    string largestGoodInteger(string num) {
        int cnt = 0;
        int prev = -1;
        int ans = -1;
        for(char& c: num){
            if(c-'0'!=prev){
                cnt = 1;
                prev = c-'0';
            }
            else
            {
                cnt++;
                if(cnt>=3)
                {
                    cout<<prev<<endl;
                    ans = max(ans, prev);
                }
            }
        }
        if(ans == -1) return "";
        else{
            string out = "";
            for(int i=0; i<3; i++)
            {
                out+=to_string(ans);
            }
            return out;
        } 
    }
};