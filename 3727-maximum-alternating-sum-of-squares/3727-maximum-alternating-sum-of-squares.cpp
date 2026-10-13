class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        vector<long long> sq;

        for (int x : nums) {
            sq.push_back(1LL * x * x);
        }

        sort(sq.begin(), sq.end());

        int n = sq.size();
        int pos = (n + 1) / 2;

        long long ans = 0;

        for (int i = 0; i < n - pos; i++) {
            ans -= sq[i];
        }

        for (int i = n - pos; i < n; i++) {
            ans += sq[i];
        }

        return ans;
    }
};