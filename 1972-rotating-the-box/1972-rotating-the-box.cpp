class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m = box.size();
        int n = box[0].size();

        for(auto& row: box){
            row.push_back('*');
            int start = 0;
            int rock = 0;
            vector<char> after_rotate;

            for(int i=0; i<=n; i++){
                cout<<row[i]<<endl;
                if(row[i] == '#') rock++;
                else if(row[i] == '*'){
                    int empty = i - start - rock;
                    for(int j=0; j<empty; j++) after_rotate.push_back('.');
                    for(int j=0; j<rock; j++) after_rotate.push_back('#');
                    after_rotate.push_back('*');
                    rock = 0;
                    start = i + 1;
                }
            }
            row = after_rotate;
            row.pop_back();
        }

        vector<vector<char>> ans;
        for(int i=0; i<n; i++){
            vector<char> temp;
            for(int j=m-1; j>=0; j--){
                temp.push_back(box[j][i]);
            }
            ans.push_back(temp);
        }

        return ans;
    }
};
/*
0 1 2 - i=2, rock = 1
0 1 2 3 -> 2에서 *, start = 2 / 3에서 rock =0, 4에서 정산 empty = 4 - 2 - 0 = 2

*/