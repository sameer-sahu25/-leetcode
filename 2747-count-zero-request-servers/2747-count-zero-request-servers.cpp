class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x,
                             vector<int>& queries) {

        sort(logs.begin(), logs.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[1] < b[1];
             });

        int m = queries.size();

        vector<pair<int, int>> q;
        for (int i = 0; i < m; i++) {
            q.push_back({queries[i], i});
        }

        sort(q.begin(), q.end());

        vector<int> ans(m);

        unordered_map<int, int> cnt;

        int active = 0;
        int l = 0, r = 0;

        for (auto& [time, idx] : q) {

            // Add logs with timestamp <= query time
            while (r < logs.size() && logs[r][1] <= time) {
                int server = logs[r][0];

                if (++cnt[server] == 1)
                    active++;

                r++;
            }

            // Remove logs with timestamp < time - x
            while (l < logs.size() && logs[l][1] < time - x) {
                int server = logs[l][0];

                if (--cnt[server] == 0)
                    active--;

                l++;
            }

            ans[idx] = n - active;
        }

        return ans;
    }
};