class NumberContainers {
public:
    unordered_map<int, int> mp;  // Maps index -> number
    map<int, set<int>> numToIndices;  // Maps number -> set of indices

    NumberContainers() {
        mp.clear();
        numToIndices.clear();
    }

    void change(int index, int number) {
        // If index already exists with a different number, remove old number from numToIndices
        if (mp.find(index) != mp.end()) {
            int oldNumber = mp[index];
            numToIndices[oldNumber].erase(index);
            if (numToIndices[oldNumber].empty()) {
                numToIndices.erase(oldNumber);
            }
        }

        // Update the new number
        mp[index] = number;
        numToIndices[number].insert(index);
    }

    int find(int number) {
        // If number exists, return the smallest index
        if (numToIndices.find(number) != numToIndices.end() && !numToIndices[number].empty()) {
            return *numToIndices[number].begin();  // Smallest index for this number
        }
        return -1;  // Not found
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */