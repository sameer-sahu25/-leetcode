class Solution {
public:
    long long calc(long long x,
                   int cost1, int cost2, int costBoth,
                   int need1, int need2) {

        return x * costBoth
             + max(0LL, (long long)need1 - x) * cost1
             + max(0LL, (long long)need2 - x) * cost2;
    }

    long long minimumCost(int cost1, int cost2, int costBoth,
                          int need1, int need2) {

        long long a = min(need1, need2);
        long long b = max(need1, need2);

        return min({
            calc(0, cost1, cost2, costBoth, need1, need2),
            calc(a, cost1, cost2, costBoth, need1, need2),
            calc(b, cost1, cost2, costBoth, need1, need2)
        });
    }
};
