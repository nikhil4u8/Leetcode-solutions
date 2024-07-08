class ProductOfNumbers {
public:
    vector<long long>temp;
    int len;
    ProductOfNumbers() {
        temp.push_back(1);
        len = 1;
    }
    
    void add(int num) {
        if(num == 0) temp = {1};
        else temp.push_back(temp[len-1]*num);
        
        len = temp.size();
    }
    
    int getProduct(int k) {
        if(k >= len) return 0;
        return temp[len-1]/temp[len-1-k];
    }
};