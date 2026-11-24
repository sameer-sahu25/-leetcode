class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            long long prod = 1;
            long long g = 0;
            long long l = 1;

            for (int j = i; j < n; j++) {

                if (prod > LLONG_MAX / nums[j])
                    break;   // would overflow

                prod *= nums[j];

                if (j == i)
                    g = nums[j];
                else
                    g = gcd(g, (long long)nums[j]);

                long long d = gcd(l, (long long)nums[j]);

                if (l > LLONG_MAX / (nums[j] / d))
                    break;   // lcm would overflow

                l = l * (nums[j] / d);

                if (prod == g * l)
                    ans = max(ans, j - i + 1);
            }
        }

        return ans;
    }
};