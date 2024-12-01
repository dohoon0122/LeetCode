class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_set<int> check_list;
        sort(arr.begin(), arr.end());
        for(int i=0; i<arr.size(); i++){
            if(check_list.count(arr[i])) return true;
            if(arr[i]<0 && arr[i]%2==0){
                check_list.insert(arr[i]/2);
            }
            else{
                check_list.insert(arr[i]*2);
            }  
        }
        return false;
    }
};