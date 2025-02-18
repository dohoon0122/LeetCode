class Solution {
public:
    string smallestNumber(string pattern) {
        string ans = "";
        stack<int> st;

        for(int i=0; i<=pattern.size(); i++){
            st.push(i+1);
            if(i==pattern.size() || pattern[i] == 'I'){
                while(!st.empty()){
                    ans+=(st.top() + '0');
                    st.pop();
                }
            }
        }

        return ans;
    }
};