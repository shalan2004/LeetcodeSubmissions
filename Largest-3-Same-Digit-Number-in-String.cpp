class Solution {
public:
    string largestGoodInteger(string num) {
        int count = 1;
        char prev = num[0];
        string ans = "";

        for (int i = 1; i < num.size(); i++) {
            if (num[i] == prev) {
                count++;
            } else {
                count = 1;
                prev = num[i];
            }

            if (count == 3) {
                string triple = string(3, prev);
                if (ans.empty() || triple > ans) {
                    ans = triple;
                }
            }
        }
        return ans;
    }
};