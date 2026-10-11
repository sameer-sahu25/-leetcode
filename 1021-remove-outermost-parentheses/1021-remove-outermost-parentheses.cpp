class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans;
        int depth = 0;

        for (char c : s) {
            if (c == '(') {
                if (depth++ > 0) ans += c;
            } else {
                if (--depth > 0) ans += c;
            }
        }
        return ans;
    }
};