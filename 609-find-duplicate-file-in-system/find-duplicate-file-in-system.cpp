
class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string, vector<string>> mp; // content -> list of full paths

        for (auto& line : paths) {
            stringstream ss(line);
            string dir;
            ss >> dir;  // first token is directory

            string token;
            while (ss >> token) {
                int lp = token.find('(');
                int rp = token.find(')');

                string name = token.substr(0, lp);
                string content = token.substr(lp + 1, rp - lp - 1);

                mp[content].push_back(dir + "/" + name);
            }
        }

        vector<vector<string>> ans;
        for (auto& [content, files] : mp) {
            if (files.size() > 1) ans.push_back(files);
        }
        return ans;
    }
};