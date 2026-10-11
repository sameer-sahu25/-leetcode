class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1,
                               vector<int>& nums2,
                               int k1,
                               int k2) {

        long long k = (long long)k1 + k2;

        vector<long long> diff;
        long long total = 0;

        for (int i = 0; i < nums1.size(); i++) {
            long long d = abs(nums1[i] - nums2[i]);
            diff.push_back(d);
            total += d;
        }

        if (k >= total) return 0;

        long long lo = 0, hi = 100000;

        while (lo < hi) {
            long long mid = (lo + hi) / 2;

            long long need = 0;
            for (auto d : diff) {
                if (d > mid)
                    need += d - mid;
            }

            if (need > k)
                lo = mid + 1;
            else
                hi = mid;
        }

        long long x = lo;

        long long used = 0;
        vector<long long> arr;

        for (auto d : diff) {
            if (d > x) {
                used += d - x;
                arr.push_back(x);
            } else {
                arr.push_back(d);
            }
        }

        long long rem = k - used;

        for (auto &d : arr) {
            if (rem > 0 && d == x) {
                d--;
                rem--;
            }
        }

        long long ans = 0;

        for (auto d : arr)
            ans += d * d;

        return ans;
    }
};