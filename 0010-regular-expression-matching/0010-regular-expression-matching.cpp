class Solution {
public:
    vector<vector<int>> dp;
    string s, p;

    bool solve(int i, int j) {
        if (j == p.size())
            return i == s.size();

        if (dp[i][j] != -1)
            return dp[i][j];

        bool firstMatch =
            (i < s.size()) &&
            (s[i] == p[j] || p[j] == '.');

        bool ans;

        if (j + 1 < p.size() && p[j + 1] == '*') {
            ans =
                solve(i, j + 2) ||
                (firstMatch && solve(i + 1, j));
        } else {
            ans =
                firstMatch &&
                solve(i + 1, j + 1);
        }

        return dp[i][j] = ans;
    }

    bool isMatch(string str, string pat) {
        s = str;
        p = pat;

        dp.assign(s.size() + 1,
                  vector<int>(p.size() + 1, -1));

        return solve(0, 0);
    }
};