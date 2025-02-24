class ProductOfNumbers {
public:
    vector<int> prefPdt; // second is to handle zeroes
    int d;
    ProductOfNumbers() {
        int d = 0;
    }
    
    void add(int num) {
        long p = 1;
        if(num != 0)
        {
            if(prefPdt.size() > 0)
            {
                p = prefPdt.back();
            }

            p *= num;
            prefPdt.push_back(p);
        }
        else prefPdt.clear();
        
    }
    
    int getProduct(int k) {
        int n =  prefPdt.size();
        if(n-k < 0)
        {
            return 0;
        }

        if(n-k == 0) return prefPdt[n-1];
        return prefPdt[n-1]/prefPdt[n-k-1];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */