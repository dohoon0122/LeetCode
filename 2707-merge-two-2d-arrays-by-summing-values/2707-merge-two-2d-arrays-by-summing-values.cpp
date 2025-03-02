class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        int left = 0, right = 0;
        int n1 = nums1.size();
        int n2 = nums2.size();
        nums1.push_back({INT_MAX, -1});
        nums2.push_back({INT_MAX, -1});
        vector<vector<int>> ans;
        while(left<n1 || right<n2){
            int id1 = nums1[left][0];
            int id2 = nums2[right][0];
            if(id1<id2){
                vector<int> temp = {id1, nums1[left][1]};
                ans.push_back(temp);
                left++;
            }
            else if(id1==id2){
                vector<int> temp = {id1, nums1[left][1] + nums2[right][1]};
                ans.push_back(temp);
                left++;
                right++;
            }
            else{
                vector<int> temp = {id2, nums2[right][1]};
                ans.push_back(temp);
                right++;
            }
        }
        return ans;
    }
};