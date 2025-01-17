class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        bool diff = true;
        for(int d: derived){
            if(d) diff=!diff;
        }
        return diff;
    }
};