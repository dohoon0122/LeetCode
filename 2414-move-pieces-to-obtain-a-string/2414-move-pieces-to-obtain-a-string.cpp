class Solution {
public:
    bool canChange(string start, string target) {
        int s = 0, t = 0;
        int n = start.size();
        while(s < n || t < n){
            while(s < n && start[s] == '_') s++;
            while(t < n && target[t] == '_') t++;

            if(s == n || t == n) return s == n && t == n;

            if(start[s] != target[t] || 
            (start[s] == 'L' && s < t) ||
            (start[s] == 'R' && s > t)) return false;

            s++;
            t++;   
        }

        return true;
    }
};