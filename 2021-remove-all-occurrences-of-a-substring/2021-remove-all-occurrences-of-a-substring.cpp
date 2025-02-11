class Solution {
public:
    string removeOccurrences(string s, string part) {
        vector<int> Pi = getPi(part);
        string st;
        for(int i=0; i<Pi.size(); i++){
            cout<<"i: "<<i<<", Pi[i]: "<<Pi[i]<<"\n";
        }


        vector<int> match(s.size()+1, 0);
        int j = 0;
        
        for(int i=0;i<s.size(); i++){
            char curr = s[i];
            st += curr;

            if(curr == part[j]){
                match[st.size()] = ++j;

                if(j == part.size()){
                    int del_size = part.size();
                    while(del_size > 0){
                        st.pop_back();
                        del_size--;
                    }

                    j = st.empty()?0:match[st.size()];
                }
            }
            else{
                if(j != 0){
                    i--;
                    j = Pi[j-1];
                    st.pop_back();
                }
                else{
                    match[st.size()] = 0;
                }
            }
        }
        

        return st;
    }

    vector<int> getPi(string& target){
        int m = target.size();
        vector<int> pi(m, 0);

        for(int i=1, j=0; i<m; i++){
            while(j>0 && target[i] != target[j]){
                j = pi[j-1];
            }
            if(target[i] == target[j]){
                pi[i] = ++j;
            }
        }
        return pi;
    }
};