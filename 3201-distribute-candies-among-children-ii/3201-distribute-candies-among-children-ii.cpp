class Solution {
public:
    long long distributeCandies(int n, int limit) {
        return solve(n+2) - 3*(solve(n-limit+1)) + 3*solve(n-(limit+1)*2 + 2) - solve(n-3*(limit+1)+2);
    }

    long long solve(int x){
        if(x < 0) return 0;
        return (long)x * (x-1) / 2;
    }
};