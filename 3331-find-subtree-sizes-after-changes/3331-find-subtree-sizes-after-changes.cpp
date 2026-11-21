class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();

        vector<vector<int>> tree(n);
        for (int i = 1; i < n; i++) {
            tree[parent[i]].push_back(i);
        }

        vector<int> newParent = parent;
        vector<int> last(26, -1);

        function<void(int)> dfs = [&](int u) {
            int c = s[u] - 'a';

            int prev = last[c];

            if (u != 0 && prev != -1)
                newParent[u] = prev;

            last[c] = u;

            for (int v : tree[u])
                dfs(v);

            last[c] = prev;
        };

        dfs(0);

        vector<vector<int>> finalTree(n);
        for (int i = 1; i < n; i++) {
            finalTree[newParent[i]].push_back(i);
        }

        vector<int> ans(n);

        function<int(int)> calc = [&](int u) {
            int sz = 1;

            for (int v : finalTree[u])
                sz += calc(v);

            return ans[u] = sz;
        };

        calc(0);

        return ans;
    }
};