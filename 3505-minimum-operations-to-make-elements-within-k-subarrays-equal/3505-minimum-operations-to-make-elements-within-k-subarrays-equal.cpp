class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();
        const long long INF = 4e18;
        struct SlidingMedian {
            multiset<int, greater<int>> left;
            multiset<int> right;
            long long sumLeft = 0;
            long long sumRight = 0;
            void rebalance() {
                while (left.size() < right.size()) {
                    int v = *right.begin();
                    right.erase(right.begin());
                    sumRight -= v;
                    sumLeft += v;
                    left.insert(v);
                }
                while (left.size() > right.size() + 1) {
                    int v = *left.begin();
                    left.erase(left.begin());
                    sumLeft -= v;
                    sumRight += v;
                    right.insert(v);
                }
            }
            void add(int x) {
                if (left.empty() || x <= *left.begin()) {
                    left.insert(x);
                    sumLeft += x;
                } else {
                    right.insert(x);
                    sumRight += x;
                }
                rebalance();
            }
            void remove(int x) {
                auto it = left.find(x);
                if (it != left.end()) {
                    left.erase(it);
                    sumLeft -= x;
                } else {
                    it = right.find(x);
                    right.erase(it);
                    sumRight -= x;
                }
                rebalance();
            }
            long long cost() {
                long long med = *left.begin();

                return med * (long long)left.size() - sumLeft +
                       sumRight - med * (long long)right.size();
            }
        };
        vector<long long> cost(n + 1, INF);
        SlidingMedian sm;
        for (int i = 0; i < n; i++) {
            if (i >= x)
                sm.remove(nums[i - x]);
            sm.add(nums[i]);
            if (i >= x - 1)
                cost[i + 1] = sm.cost();
        }

        vector<long long> dp(n + 1, 0);

        for (int take = 1; take <= k; take++) {
            vector<long long> ndp(n + 1, INF);

            for (int j = take * x; j <= n; j++) {
                ndp[j] = ndp[j - 1];

                if (dp[j - x] != INF) {
                    ndp[j] = min(
                        ndp[j],
                        dp[j - x] + cost[j]
                    );
                }
            }
            dp.swap(ndp);
        }
        return dp[n];
    }
};