class Solution {
public:
    static constexpr long long MOD = 1e9 + 7;

    struct SegTree {
        int n;
        vector<long long> tree, lazy;

        SegTree(int n) : n(n) {
            tree.assign(4 * n + 5, 0);
            lazy.assign(4 * n + 5, 0);
        }

        void apply(int node, int l, int r, long long val) {
            tree[node] += (r - l + 1) * val;
            lazy[node] += val;
        }

        void push(int node, int l, int r) {
            if (!lazy[node]) return;

            int mid = (l + r) >> 1;

            apply(node << 1, l, mid, lazy[node]);
            apply(node << 1 | 1, mid + 1, r, lazy[node]);

            lazy[node] = 0;
        }

        void update(int node, int l, int r,
                    int ql, int qr, long long val) {
            if (ql > r || qr < l) return;

            if (ql <= l && r <= qr) {
                apply(node, l, r, val);
                return;
            }

            push(node, l, r);

            int mid = (l + r) >> 1;

            update(node << 1, l, mid, ql, qr, val);
            update(node << 1 | 1, mid + 1, r, ql, qr, val);

            tree[node] = tree[node << 1] + tree[node << 1 | 1];
        }

        long long query(int node, int l, int r,
                        int ql, int qr) {
            if (ql > r || qr < l) return 0;

            if (ql <= l && r <= qr)
                return tree[node];

            push(node, l, r);

            int mid = (l + r) >> 1;

            return query(node << 1, l, mid, ql, qr)
                 + query(node << 1 | 1, mid + 1, r, ql, qr);
        }

        void update(int l, int r, long long val) {
            update(1, 0, n - 1, l, r, val);
        }

        long long query(int l, int r) {
            return query(1, 0, n - 1, l, r);
        }
    };

    int sumCounts(vector<int>& nums) {
        int n = nums.size();

        SegTree seg(n);

        unordered_map<int, int> last;

        long long ans = 0;
        long long cur = 0;

        for (int r = 0; r < n; r++) {
            int p = last.count(nums[r]) ? last[nums[r]] : -1;

            long long rangeSum = seg.query(p + 1, r);

            cur += 2LL * rangeSum + (r - p);

            seg.update(p + 1, r, 1);

            ans = (ans + cur) % MOD;

            last[nums[r]] = r;
        }

        return (int)ans;
    }
}; 