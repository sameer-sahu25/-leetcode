class Solution {
public:
    int minimumChanges(string s, int k) {
        int n = s.size();

        vector<vector<int>> cost(n, vector<int>(n, 1e9));

        // cost[l][r]
        for (int l = 0; l < n; l++) {
            for (int r = l + 1; r < n; r++) {
                int len = r - l + 1;

                // try every valid divisor
                for (int d = 1; d < len; d++) {
                    if (len % d) continue;

                    int m = len / d;
                    int cur = 0;

                    for (int start = 0; start < d; start++) {
                        int L = 0;
                        int R = m - 1;

                        while (L < R) {
                            char a = s[l + start + L * d];
                            char b = s[l + start + R * d];

                            if (a != b) cur++;

                            L++;
                            R--;
                        }
                    }

                    cost[l][r] = min(cost[l][r], cur);
                }
            }
        }

        const int INF = 1e9;

        vector<vector<int>> dp(n + 1,
                               vector<int>(k + 1, INF));

        dp[0][0] = 0;

        for (int i = 1; i <= n; i++) {
            for (int part = 1; part <= k; part++) {

                for (int p = 0; p < i; p++) {

                    int len = i - p;

                    if (len < 2) continue;

                    if (dp[p][part - 1] == INF)
                        continue;

                    dp[i][part] =
                        min(dp[i][part],
                            dp[p][part - 1] +
                            cost[p][i - 1]);
                }
            }
        }

        return dp[n][k];
    }
};