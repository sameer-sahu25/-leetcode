class Solution {
public:
    vector<vector<int>> g;
    vector<int> parent, depth, heavy, head, pos, sz;
    int curPos;

    struct SegTree {
        int n;
        vector<int> tree;

        SegTree(int n) {
            this->n = n;
            tree.assign(4 * n, 0);
        }

        void build(int node, int l, int r, vector<int>& arr) {
            if (l == r) {
                tree[node] = arr[l];
                return;
            }

            int mid = (l + r) >> 1;

            build(node << 1, l, mid, arr);
            build(node << 1 | 1, mid + 1, r, arr);

            tree[node] = tree[node << 1] ^ tree[node << 1 | 1];
        }

        void update(int node, int l, int r, int idx, int val) {
            if (l == r) {
                tree[node] = val;
                return;
            }

            int mid = (l + r) >> 1;

            if (idx <= mid)
                update(node << 1, l, mid, idx, val);
            else
                update(node << 1 | 1, mid + 1, r, idx, val);

            tree[node] = tree[node << 1] ^ tree[node << 1 | 1];
        }

        int query(int node, int l, int r, int ql, int qr) {
            if (qr < l || r < ql)
                return 0;

            if (ql <= l && r <= qr)
                return tree[node];

            int mid = (l + r) >> 1;

            return query(node << 1, l, mid, ql, qr) ^
                   query(node << 1 | 1, mid + 1, r, ql, qr);
        }
    };

    int dfs(int u, int p) {
        parent[u] = p;
        sz[u] = 1;

        int maxSubtree = 0;

        for (int v : g[u]) {
            if (v == p) continue;

            depth[v] = depth[u] + 1;

            int subtree = dfs(v, u);
            sz[u] += subtree;

            if (subtree > maxSubtree) {
                maxSubtree = subtree;
                heavy[u] = v;
            }
        }

        return sz[u];
    }

    void decompose(int u, int h) {
        head[u] = h;
        pos[u] = curPos++;

        if (heavy[u] != -1)
            decompose(heavy[u], h);

        for (int v : g[u]) {
            if (v == parent[u] || v == heavy[u]) continue;
            decompose(v, v);
        }
    }

    int pathQuery(int u, int v, SegTree& seg, int n) {
        int res = 0;

        while (head[u] != head[v]) {
            if (depth[head[u]] < depth[head[v]])
                swap(u, v);

            res ^= seg.query(
                1,
                0,
                n - 1,
                pos[head[u]],
                pos[u]
            );

            u = parent[head[u]];
        }

        if (depth[u] > depth[v])
            swap(u, v);

        res ^= seg.query(
            1,
            0,
            n - 1,
            pos[u],
            pos[v]
        );

        return res;
    }

    vector<bool> palindromePath(
        int n,
        vector<vector<int>>& edges,
        string s,
        vector<string>& queries
    ) {
        g.assign(n, {});

        for (auto& e : edges) {
            int u = e[0];
            int v = e[1];

            g[u].push_back(v);
            g[v].push_back(u);
        }

        parent.assign(n, -1);
        depth.assign(n, 0);
        heavy.assign(n, -1);
        head.assign(n, 0);
        pos.assign(n, 0);
        sz.assign(n, 0);

        curPos = 0;

        dfs(0, -1);
        decompose(0, 0);

        vector<int> base(n);

        for (int i = 0; i < n; i++) {
            base[pos[i]] = 1 << (s[i] - 'a');
        }

        SegTree seg(n);
        seg.build(1, 0, n - 1, base);

        vector<bool> ans;

        for (string& q : queries) {
            stringstream ss(q);

            string type;
            ss >> type;

            if (type == "update") {
                int u;
                char c;

                ss >> u >> c;

                s[u] = c;

                seg.update(
                    1,
                    0,
                    n - 1,
                    pos[u],
                    1 << (c - 'a')
                );
            }
            else {
                int u, v;
                ss >> u >> v;

                int mask = pathQuery(u, v, seg, n);

                ans.push_back(__builtin_popcount(mask) <= 1);
            }
        }

        return ans;
    }
};