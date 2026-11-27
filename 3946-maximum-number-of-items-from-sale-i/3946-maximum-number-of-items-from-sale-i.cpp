class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();

        vector<int> bonus(n, 1);

        for (int i = 0; i < n; i++) {
            int fi = items[i][0];

            for (int j = 0; j < n; j++) {
                if (i == j) continue;

                if (items[j][0] % fi == 0)
                    bonus[i]++;
            }
        }

        vector<int> dp(budget + 1, 0);

        for (int i = 0; i < n; i++) {
            int cost = items[i][1];

            vector<int> ndp = dp;

            for (int b = cost; b <= budget; b++) {
                // First purchase of this item type
                ndp[b] = max(ndp[b], dp[b - cost] + bonus[i]);

                // Additional copies
                ndp[b] = max(ndp[b], ndp[b - cost] + 1);
            }

            dp.swap(ndp);
        }

        return *max_element(dp.begin(), dp.end());
    }
};
