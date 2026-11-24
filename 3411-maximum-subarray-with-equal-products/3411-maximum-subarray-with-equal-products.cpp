class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 1;

        for (int i = 0; i < n; i++) {
            long long prod = 1;
            long long g = 0;
            long long l = 1;

            for (int j = i; j < n; j++) {
                prod *= nums[j];

                if (j == i)
                    g = nums[j];
                else
                    g = gcd(g, (long long)nums[j]);

                l = l / gcd(l, (long long)nums[j]) * nums[j];

                if (prod == g * l)
                    ans = max(ans, j - i + 1);
            }
        }

        return ans;
    }
};