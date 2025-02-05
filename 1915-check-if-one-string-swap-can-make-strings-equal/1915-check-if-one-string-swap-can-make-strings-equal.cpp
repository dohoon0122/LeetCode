class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int n = s1.size();
        int mismatch = 0;
        char s1_flag, s2_flag;
        bool SwapEqual = true;
        for(int i=0; i<n; ++i)
        {
            if(s1[i]!=s2[i])
            {
                if(mismatch>=2)
                {
                    return false;
                }
                else if(mismatch == 1)
                {
                    if(s1[i] != s2_flag || s2[i] != s1_flag)
                    {
                        return false;
                    }
                    SwapEqual = true;
                }
                else
                {
                    s1_flag = s1[i];
                    s2_flag = s2[i];
                    SwapEqual = false;
                }
                mismatch++;
            }
        }
        return SwapEqual;
    }
};