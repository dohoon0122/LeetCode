class Solution {
public:
    bool checkPowersOfThree(int n) {
        return backtrack(0, n);
    }

    bool backtrack(int power, int n) {
        if (n == 0) return true;

        if (pow(3, power) > n) return false;

        bool addPower = backtrack(power + 1, n - pow(3, power));

        bool skipPower = backtrack(power + 1, n);

        return addPower || skipPower;
    }
};