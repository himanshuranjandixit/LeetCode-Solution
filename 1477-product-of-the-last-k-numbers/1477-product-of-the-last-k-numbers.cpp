class ProductOfNumbers {
public:
    vector<int>v;
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        v.push_back(num);
        
    }
    
    int getProduct(int k) {
        int ans=1;
        int i=v.size()-1;
        while(k>0){
            ans*=v[i];
            i--;
            k--;
        }
        return ans;
        
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */