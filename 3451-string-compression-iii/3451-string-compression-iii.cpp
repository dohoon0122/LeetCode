class Solution {
public:
    string compressedString(string word) {
        string comp = "";

        int len = 0;
        char prev = '\0';

        for(char& c: word){
            if(c!=prev){ 
                if(prev){
                    if(len>9){
                        while(len>9){
                            comp+='9';
                            comp+=prev;
                            len-=9;
                        }
                    }
                    comp+=len+'0';
                    comp+=prev;
                    
                }
                len = 1;
                prev = c;
            }
            else{
                len++;
            }
        }
        if(len>9){
            while(len>9){
                comp+='9';
                comp+=prev;
                len-=9;
            }
        }
        comp+=len+'0';
        comp+=prev;

        return comp;
    }
};