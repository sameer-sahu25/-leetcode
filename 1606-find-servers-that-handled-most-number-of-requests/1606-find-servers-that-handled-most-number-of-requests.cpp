class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        vector<int> handled(k, 0);

      
        set<int> available;
        for (int i = 0; i < k; i++) {
            available.insert(i);
        }

       
        priority_queue<
            pair<long long, int>,
            vector<pair<long long, int>>,
            greater<pair<long long, int>>
        > busy;

        for (int i = 0; i < arrival.size(); i++) {

        
            while (!busy.empty() && busy.top().first <= arrival[i]) {
                available.insert(busy.top().second);
                busy.pop();
            }

            if (available.empty()) continue;

            int target = i % k;

            auto it = available.lower_bound(target);

            if (it == available.end()) {
                it = available.begin();   
            }

            int server = *it;
            available.erase(it);

            handled[server]++;

            busy.push({
                (long long)arrival[i] + load[i],
                server
            });
        }

        int mx = *max_element(handled.begin(), handled.end());

        vector<int> ans;
        for (int i = 0; i < k; i++) {
            if (handled[i] == mx) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};