class ProductOfNumbers {
public:
    vector<int> pref;
    int n;
    ProductOfNumbers() {
        pref.clear();
        n=0;
    }

    void add(int num) {
        if (num == 0) {
            pref = {};
            n = 0;
        } else {
            if (pref.empty()) {
                pref.push_back(num);
            } else
                pref.push_back(pref[n-1] * num);
            n++;
        }
    }

    int getProduct(int k) {
        if (k > n)
            return 0;
        else if (k == n)
            return pref[n-1];
        return pref[n - 1] / pref[n - k - 1];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */