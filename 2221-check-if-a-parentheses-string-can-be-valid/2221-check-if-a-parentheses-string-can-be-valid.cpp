class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.size();
        if (n % 2 != 0) return false;

        int balance = 0;
        int flexible = 0;
        for (int i = 0; i < n; ++i) {
            if (locked[i] == '1') {
                balance += (s[i] == '(' ? 1 : -1);
            } else {
                flexible++;
            }
            if (balance + flexible < 0) return false;
        }

        balance = 0;
        flexible = 0;
        for (int i = n - 1; i >= 0; --i) {
            if (locked[i] == '1') {
                balance += (s[i] == ')' ? 1 : -1);
            } else {
                flexible++;
            }
            if (balance + flexible < 0) return false;
        }

        return true;
    }
};