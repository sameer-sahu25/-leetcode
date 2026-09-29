class Solution {
public:
    int m, n;
    vector<vector<vector<int>>> dp;

    bool dfs(int i, int j, int bal, vector<vector<char>>& grid) {
        if (bal < 0) return false;

        int rem = (m - 1 - i) + (n - 1 - j);
        if (bal > rem + 1) return false;

        if (i == m - 1 && j == n - 1)
            return bal == 0;

        if (dp[i][j][bal] != -1)
            return dp[i][j][bal];

        bool ans = false;

        if (i + 1 < m) {
            int nb = bal + (grid[i + 1][j] == '(' ? 1 : -1);
            ans |= dfs(i + 1, j, nb, grid);
        }

        if (!ans && j + 1 < n) {
            int nb = bal + (grid[i][j + 1] == '(' ? 1 : -1);
            ans |= dfs(i, j + 1, nb, grid);
        }

        return dp[i][j][bal] = ans;
    }

    bool hasValidPath(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();

        if (grid[0][0] == ')') return false;
        if (grid[m - 1][n - 1] == '(') return false;

        int len = m + n - 1;
        if (len & 1) return false;

        dp.assign(m,
                  vector<vector<int>>(n,
                  vector<int>(m + n + 1, -1)));

        return dfs(0, 0, 1, grid);
    }
};