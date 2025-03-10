class Solution {
public:
    bool isVowel(char& ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }
    long long countOfSubstrings(string word, int k) {
        unordered_map<char, int> mp;

        long long int i = 0, j = 0, count = 0;
        int n = word.size();
        int total_consonants = 0;
        vector<int> nextCons(n);
        int lastidx = n;
        for (int i = n - 1; i >= 0; i--) {
            nextCons[i]=lastidx;
            if(!isVowel(word[i])){
                lastidx = i;
            }   
        }
        while (j < n) {
            char c = word[j];
            if (isVowel(c))
                mp[c]++;
            else {
                total_consonants++;
            }

            while (total_consonants > k) {
                char c = word[i];
                if (isVowel(c)) {
                    mp[c]--;
                    if (mp[c] == 0)
                        mp.erase(c);
                } else {
                    total_consonants--;
                }
                i++;
            }
            while (i < n && total_consonants == k && mp.size() == 5) {
                int idx = nextCons[j];
                count += idx - j;
                char c = word[i];
                if (isVowel(c)) {
                    mp[c]--;
                    if (mp[c] == 0)
                        mp.erase(c);
                } else {
                    total_consonants--;
                }
                i++;
            }

            j++;
        }
        return count;
    }
};