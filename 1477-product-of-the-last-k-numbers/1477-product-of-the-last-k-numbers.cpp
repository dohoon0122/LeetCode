class ProductOfNumbers {
public:
    ProductOfNumbers() {
        mul_vec.push_back(1);
        size = 0;
    }
    
    void add(int num) {
        if(num==0){
            mul_vec = {1};
            size = 0;
        }
        else{
            mul_vec.push_back(mul_vec[size] * num);
            size++;
        }
    }
    
    int getProduct(int k) {
        if(k>size) return 0;
        return mul_vec[size] / mul_vec[size - k];
    }
private:
    vector<int> mul_vec;
    int size = 0;
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */