class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> mp;

        for (auto &it : knowledge) {
            mp[it[0]] = it[1];
        }

        string ans = "";
        int n = s.size();

        for (int i = 0; i < n; i++) {
            if (s[i] != '(') {
                ans += s[i];
            } else {
                string key = "";
                i++; // move after '('

                while (i < n && s[i] != ')') {
                    key += s[i];
                    i++;
                }

                if (mp.count(key))
                    ans += mp[key];
                else
                    ans += '?';
            }
        }

        return ans;
    }
};