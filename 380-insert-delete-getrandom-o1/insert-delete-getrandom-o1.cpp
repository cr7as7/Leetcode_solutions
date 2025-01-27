class RandomizedSet {
public:
    /** Initialize your data structure here. */
    unordered_map<int, int> m;
    vector<int> a;
    RandomizedSet() {}

    /** Inserts a value to the set. Returns true if the set did not already
     * contain the specified element. */
    bool insert(int val) {
        if (m.find(val) != m.end())
            return false;

        a.push_back(val);
        m[val] = a.size() - 1;
        return true;
    }

    /** Removes a value from the set. Returns true if the set contained the
     * specified element. */
    bool remove(int val) {
        if (m.find(val) == m.end())
            return false;
        int lastEle = a.back();
        a[m[val]] = lastEle;
        m[lastEle] = m[val];
        a.pop_back();
        m.erase(val);

        return true;
    }

    /** Get a random element from the set. */
    int getRandom() { return a[rand() % a.size()]; }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */