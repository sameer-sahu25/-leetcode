#include <vector>
using namespace std;

class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> ans(k, 0);
        vector<long long> dp(k, 0);
        for (int x : nums) {
            int a = x % k;
            vector<long long> ndp(k, 0);
            ndp[a]++;
            for (int r = 0; r < k; r++) {
                if (dp[r] == 0) continue;
                ndp[(r * a) % k] += dp[r];
            }
            for (int r = 0; r < k; r++) {
                ans[r] += ndp[r];
            }
            dp = std::move(ndp);
        }
        return ans;
    }
};
