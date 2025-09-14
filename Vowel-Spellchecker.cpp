class Solution {
public:
    vector<string> spellchecker(vector<string>& W, vector<string>& Q) {
        set<string> orig (W.begin(), W.end());
        unordered_map<string, string> lower, mask;
        for (int i = W.size() - 1; ~i; i--) {
            string word = W[i], wlow = lcase(word);
            lower[wlow] = word, mask[vmask(wlow)] = word;
        }
        for (string &query : Q) {
            string qlow = lcase(query), qmask = vmask(qlow);
            if (orig.count(query)) continue;
            else if (lower.count(qlow)) query = lower[qlow];
            else if (mask.count(qmask)) query = mask[qmask];
            else query = "";
        }
        return Q;
    }
    static string vmask(string str) {
        for (char &c : str)
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
                c = '*';
        return str;
    }
    static string lcase(string str) {
        for (char &c : str) c = tolower(c);
        return str;
    }
};