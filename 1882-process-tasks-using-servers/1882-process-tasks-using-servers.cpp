class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {

        using ll = long long;

        // (weight, index)
        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > available;

        // (freeTime, weight, index)
        priority_queue<
            tuple<ll,int,int>,
            vector<tuple<ll,int,int>>,
            greater<tuple<ll,int,int>>
        > busy;

        int n = servers.size();
        int m = tasks.size();

        for (int i = 0; i < n; i++) {
            available.push({servers[i], i});
        }

        vector<int> ans(m);

        for (int i = 0; i < m; i++) {

            // Release servers which have finished by time i
            while (!busy.empty() && get<0>(busy.top()) <= i) {
                auto [freeTime, weight, idx] = busy.top();
                busy.pop();
                available.push({weight, idx});
            }

            if (!available.empty()) {

                auto [weight, idx] = available.top();
                available.pop();

                ans[i] = idx;

                busy.push({
                    (long long)i + tasks[i],
                    weight,
                    idx
                });

            } else {

                auto [freeTime, weight, idx] = busy.top();
                busy.pop();

                ans[i] = idx;

                busy.push({
                    freeTime + tasks[i],
                    weight,
                    idx
                });
            }
        }

        return ans;
    }
};