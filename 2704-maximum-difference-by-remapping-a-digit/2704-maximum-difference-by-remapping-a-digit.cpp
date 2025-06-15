class Solution {
public:
    int minMaxDifference(int num) {
        string s = to_string(num);
        string temp = s;
        size_t pos = s.find_first_not_of('9');
        if(pos!=string::npos){
            char a = s[pos];
            replace(s.begin(), s.end(), a, '9');
        }
        char b = temp[0];
        replace(temp.begin(), temp.end(), b, '0');
        return stoi(s) - stoi(temp);
    }
};