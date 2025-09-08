class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        vector<int> ans;
        vector<pair<int, int>> magic = {{1, 9}, {2, 9}};
        for(int i=2; i<=9; i++)
        {
            magic.push_back({1, i-1});
        }

        string a = "";
        string b = "";
        while(n)
        {
            if(n==1)
            {
                a+='1';
                break;
            }
            
            int last = n%10;
            a += to_string(magic[last].first);
            b += to_string(magic[last].second);
            n/=10;
            if(last <= 1)
            {
                n--;
            }
        }
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        ans.push_back(stoi(a));
        ans.push_back(stoi(b));
        return ans;
    }
};

/*
5031
2512
2529
*/