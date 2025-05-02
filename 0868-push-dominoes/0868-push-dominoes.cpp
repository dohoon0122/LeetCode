class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size();
        int loop_count = 0;
        string new_dominoes = dominoes;
        while(loop_count<n)
        {   
            int change_count = 0;
            for(int i=0; i<n; i++)
            {
                if(dominoes[i] == '.')
                {
                    bool pushed_from_left = false;
                    bool pushed_from_right = false;
                    if(i-1>=0 && dominoes[i-1]=='R')
                    {
                        pushed_from_left = true;
                    }
                    if(i+1<n && dominoes[i+1]=='L')
                    {
                        pushed_from_right = true;
                    }

                    if(pushed_from_left){
                        if(pushed_from_right){
                            continue;
                        }
                        else{
                            new_dominoes[i] = 'R';
                            change_count++;
                        }  
                    }
                    else if(pushed_from_right){
                        new_dominoes[i] = 'L';
                        change_count++;
                    }
                }
            }
            dominoes = new_dominoes;
            if(change_count == 0) break;
        }
        return dominoes;
    }
};