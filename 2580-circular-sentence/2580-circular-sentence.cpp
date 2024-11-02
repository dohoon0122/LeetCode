class Solution {
public:
    bool isCircularSentence(string sentence) {
        stringstream ss(sentence);
        string tmp;

        vector<string> circular_check;
        while(getline(ss, tmp, ' ')){
            circular_check.push_back(tmp);
        }
        circular_check.push_back(circular_check[0]);

        char first = circular_check[0].front();
        char last = circular_check[0].back();

        if(circular_check.size() == 1){
            if(first == last) return true;
        }
        else{
            for(int i = 1; i<circular_check.size(); i++){
                char curr_first = circular_check[i].front();
                char curr_last = circular_check[i].back();

                if(curr_first == last){
                    last = curr_last;
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
};