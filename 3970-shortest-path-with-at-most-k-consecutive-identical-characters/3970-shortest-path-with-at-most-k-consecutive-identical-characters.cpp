class Solution {
public:
    long long shortestPath(int n, vector<vector<int>>& edges,
                           string labels, int k) {
        
        vector<vector<pair<int,int>>> adj(n);

        for (auto &e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
        }

        const long long INF = 4e18;

        vector<vector<long long>> dist(n, vector<long long>(k + 1, INF));

        using T = tuple<long long,int,int>;
        priority_queue<T, vector<T>, greater<T>> pq;

        dist[0][1] = 0;
        pq.push({0, 0, 1});

        while (!pq.empty()) {
            auto [d, u, cnt] = pq.top();
            pq.pop();

            if (d != dist[u][cnt]) continue;

            for (auto &[v, w] : adj[u]) {

                int newCnt;

                if (labels[v] == labels[u]) {
                    newCnt = cnt + 1;

                    if (newCnt > k) continue;
                } else {
                    newCnt = 1;
                }

                long long nd = d + w;

                if (nd < dist[v][newCnt]) {
                    dist[v][newCnt] = nd;
                    pq.push({nd, v, newCnt});
                }
            }
        }

        long long ans = INF;

        for (int cnt = 1; cnt <= k; cnt++) {
            ans = min(ans, dist[n - 1][cnt]);
        }

        return ans == INF ? -1 : ans;
    }
};