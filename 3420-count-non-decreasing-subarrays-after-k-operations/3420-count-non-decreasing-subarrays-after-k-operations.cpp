class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        long long ans = 0;
        long long cost = 0;

        // (value, frequency)
        deque<pair<int, int>> dq;

        int j = nums.size() - 1;

        for (int i = nums.size() - 1; i >= 0; --i) {
            int num = nums[i];
            int cnt = 1;

            while (!dq.empty() && dq.back().first < num) {
                auto [v, c] = dq.back();
                dq.pop_back();

                cnt += c;
                cost += 1LL * (num - v) * c;
            }

            dq.push_back({num, cnt});

            while (cost > k) {
                auto [v, c] = dq.front();
                dq.pop_front();

                cost -= 1LL * (v - nums[j]);

                if (c > 1)
                    dq.push_front({v, c - 1});

                --j;
            }

            ans += (j - i + 1);
        }

        return ans;
    }
};
