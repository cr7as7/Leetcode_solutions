class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products,
                                             string searchWord) {
        sort(products.begin(), products.end());
        vector<vector<string>> res;
        vector<string> temp;
        string curr = "";
        for (auto c : searchWord) {
            curr += c;
            temp.clear();
            for (int i = 0; i < products.size(); i++) {
                string s = products[i];
                if (s.substr(0, curr.size()) == curr) {
                    temp.push_back(products[i]);
                }
                if (temp.size() == 3)
                    break;
            }
            res.push_back(temp);
        }
        return res;
    }
};