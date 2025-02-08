class NumberContainers {
public:
    NumberContainers() {
    }
    
    void change(int index, int number) {
        if(idx_to_num.count(index)){
            int prev = idx_to_num[index];
            num_to_idx[prev].erase(index);
            if(num_to_idx[prev].empty()) num_to_idx.erase(prev);
        }
        idx_to_num[index] = number;
        num_to_idx[number].insert(index);
    }
    
    int find(int number) {
        if(num_to_idx.count(number)){
            return *num_to_idx[number].begin();
        }
        return -1;
    }
private:
    unordered_map<int, set<int>> num_to_idx;
    unordered_map<int, int> idx_to_num;
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */