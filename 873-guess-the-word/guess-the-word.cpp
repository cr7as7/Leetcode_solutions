/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
class Solution {
public:
    int match(string& a, string& b) {
        int cnt = 0;
        for (int i = 0; i < 6; i++)
            if (a[i] == b[i])
                cnt++;
        return cnt;
    }
    string pickNextWord(vector<string>& words) {
        int n = words.size();
        int bestScore = INT_MAX;
        string bestWord = words[0];

        for (string& w1 : words) {
            vector<int> freq(7, 0);
            for (string& w2 : words) {
                if (w1 == w2)
                    continue;
                int m = match(w1, w2);
                freq[m]++;
            }
            int worst = *max_element(freq.begin(), freq.end());
            if (worst < bestScore) {
                bestScore = worst;
                bestWord = w1;
            }
        }
        return bestWord;
    }
    void findSecretWord(vector<string>& words, Master& master) {
        for (int attempt = 0; attempt < 30; attempt++) {
            string guessWord = pickNextWord(words);
            int matches = master.guess(guessWord);
            if (matches == 6)
                return;
            vector<string> newWords;
            for (string& w : words)
                if (match(w, guessWord) == matches)
                    newWords.push_back(w);
            words = newWords;
        }
    }
};