class Solution {
public:
    bool isRotation(vector<int>& a, vector<int>& b) {
        int n = a.size();

        vector<int> text = a;
        text.insert(text.end(), a.begin(), a.end());

        vector<int> pat = b;

        vector<int> lps(n, 0);

        for (int i = 1, len = 0; i < n;) {
            if (pat[i] == pat[len]) {
                lps[i++] = ++len;
            } else if (len) {
                len = lps[len - 1];
            } else {
                lps[i++] = 0;
            }
        }

        for (int i = 0, j = 0; i < 2 * n; ) {
            if (text[i] == pat[j]) {
                i++;
                j++;
                if (j == n) return true;
            } else if (j) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }

        return false;
    }

    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();

        vector<int> sortedNums = nums;
        sort(sortedNums.begin(), sortedNums.end());

        long long ans = 0;

        vector<int> divisors;
        for (int d = 1; d * d <= n; d++) {
            if (n % d == 0) {
                divisors.push_back(d);
                if (d * d != n)
                    divisors.push_back(n / d);
            }
        }

        for (int k : divisors) {
            bool ok = true;

            for (int st = 0; st < n; st += k) {
                vector<int> a(
                    nums.begin() + st,
                    nums.begin() + st + k
                );

                vector<int> b(
                    sortedNums.begin() + st,
                    sortedNums.begin() + st + k
                );

                if (!isRotation(a, b)) {
                    ok = false;
                    break;
                }
            }

            if (ok) ans += k;
        }

        return (int)ans;
    }
};