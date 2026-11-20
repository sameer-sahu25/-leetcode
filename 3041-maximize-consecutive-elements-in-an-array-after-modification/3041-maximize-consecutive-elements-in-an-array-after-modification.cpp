class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        unordered_map<int, int> dp;
        int ans = 1;

        for (int x : nums) {
            int keep = dp[x];
            int inc  = dp[x + 1];

            dp[x + 1] = max(dp[x + 1], keep + 1);
            dp[x] = max(dp[x], dp[x - 1] + 1);

            ans = max({ans, dp[x], dp[x + 1]});
        }

        return ans;
    }
};